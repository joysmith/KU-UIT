# 3. Create a basic game engine loop including input handling, update logic, and rendering

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

1. Go to GameObject--> UI --> Canvas
1. Go to GameObject--> UI --> Text
1. In Hierarchy select Text-gameObj change properties from inspector
   - center align
   - increase font size
   - increase bounding box size from scene
   - Text Input: Game Over
   - color:
1. In Hierarchy select Canvas-gameObj change properties from inspector

- Canvas Scaler
  - UI Scale mode: Scale with screen size

1.
