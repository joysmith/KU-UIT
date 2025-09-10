# 3. Create a basic game engine loop including input handling, update logic, and rendering

### Moving Player

<img src="../images/directional light.png" width="700">

1. Open unity Hub create a new project--> universal 3d--> create
1. In "Scene" click on 2D mode.
1. In "Hierarchy panel" select "Main camera" then change properties of component

   - Camera Component:

     - Projection: Orthographic

   - Environment:
     - Background type: Solid color
     - Background: **custom color**

1. Go to GameObject--> 3D Object--> Cube, rename it to player. Also In Inspector reset all transform, move it down.
1. In "Project panel" create new script name it "PlayerController" and add it to cube-GameObject

#### Enable both input systems simultaneously:

- This allows you to use both the old UnityEngine.Input class and the new Input System package within the same project.
- Navigate to Edit > Project Settings > Player.
  - Under Other Settings, locate the Active Input Handling setting: Change the value to "Both".

Unity will restart. After the restart, your PlayerController script should function correctly without errors.

```c#
using UnityEngine;
using System.Collections;

public class PlayerController : MonoBehaviour {

	public float speed = 7;

	float screenHalfWidthInWorldUnits;

	// Use this for initialization
	void Start () {

		float halfPlayerWidth = transform.localScale.x / 2f;
		screenHalfWidthInWorldUnits = Camera.main.aspect * Camera.main.orthographicSize + halfPlayerWidth;

	}

	// Update is called once per frame
	void Update () {

		float inputX = Input.GetAxisRaw ("Horizontal");
		float velocity = inputX * speed;
		transform.Translate (Vector2.right * velocity * Time.deltaTime);

		if (transform.position.x < -screenHalfWidthInWorldUnits) {
			transform.position = new Vector2 (screenHalfWidthInWorldUnits, transform.position.y);
		}

		if (transform.position.x > screenHalfWidthInWorldUnits) {
			transform.position = new Vector2 (-screenHalfWidthInWorldUnits, transform.position.y);
		}

	}
}
```

### Spawning Random Object

1. Go to GameObject--> 3D Object--> Sphere, rename it to FallingCircle. Also In Inspector reset all transform.
1. In "Project panel" create new script name it "FallingObject" and add it to FallingCircle-GameObject

```c#
using UnityEngine;
using System.Collections;

public class FallingBlock : MonoBehaviour {

	float speed = 7;


	void Update () {
		transform.Translate (Vector3.down * speed * Time.deltaTime, Space.Self);
	}
}
```

1. In "Hierarchy window" select FallingCircle then drag and drop into "Project Window" to make prefab
1. Now In "Hierarchy window" select FallingCircle-gameObject and delete it.
1. Go to GameObject--> "Create Empty" gameObject name it "spawner"
1. In "Project panel" create new script name it "SpawnManager" and add it to spawner-GameObject

```c#
using UnityEngine;
using System.Collections;

public class Spawner : MonoBehaviour {

	public GameObject fallingBlockPrefab;
	public float secondsBetweenSpawns = 1;
	float nextSpawnTime;

	public Vector2 spawnSizeMinMax;
	public float spawnAngleMax;

	Vector2 screenHalfSizeWorldUnits;

	// Use this for initialization
	void Start () {
		screenHalfSizeWorldUnits = new Vector2 (Camera.main.aspect * Camera.main.orthographicSize, Camera.main.orthographicSize);
	}

	// Update is called once per frame
	void Update () {

		if (Time.time > nextSpawnTime) {
			nextSpawnTime = Time.time + secondsBetweenSpawns;

			float spawnAngle = Random.Range (-spawnAngleMax, spawnAngleMax);
			float spawnSize = Random.Range (spawnSizeMinMax.x, spawnSizeMinMax.y);
			Vector2 spawnPosition = new Vector2 (Random.Range (-screenHalfSizeWorldUnits.x, screenHalfSizeWorldUnits.x), screenHalfSizeWorldUnits.y + spawnSize);
			GameObject newBlock = (GameObject)Instantiate (fallingBlockPrefab, spawnPosition, Quaternion.Euler(Vector3.forward * spawnAngle));
			newBlock.transform.localScale = Vector2.one * spawnSize;
		}

	}
}
```

1. Open "FallingObject.cs" destroying gameObject when fall below height

```c#
using UnityEngine;
using System.Collections;

public class FallingBlock : MonoBehaviour {

	public Vector2 speedMinMax;
	float speed;

	float visibleHeightThreshold;

	void Start() {
		speed = Mathf.Lerp (speedMinMax.x, speedMinMax.y, Difficulty.GetDifficultyPercent ());

		visibleHeightThreshold = -Camera.main.orthographicSize - transform.localScale.y;
	}

	void Update () {
		transform.Translate (Vector3.down * speed * Time.deltaTime, Space.Self);

		if (transform.position.y < visibleHeightThreshold) {
			Destroy (gameObject);
		}
	}
}
```

### Working With UI
