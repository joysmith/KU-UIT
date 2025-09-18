# 3. Create a basic game engine loop including input handling, update logic, and rendering

### Moving Player

<img src="../images/directional light.png" width="700">

1. Open unity Hub create a new project--> universal 3d--> create
1. In "Scene" click on 2D mode.
1. In "Game mode" click on aspect-->add new item-->Type: aspect(x:3, y:5)
1. In "Hierarchy panel" select "Main camera" then change properties of component

   - Camera Component:

     - Projection: Orthographic

   - Environment:
     - Background type: Solid color
     - Background: **custom color**

1. Go to GameObject--> 3D Object--> Cube, rename it to "player". Also In Inspector reset all transform, move it down.

#### Giving material

1. Create new folder call it material inside it, right click--> material rename to "player"
   - Component shader: unlit--> color --> **custom color**
1. Drag and drop player-material on player-gameObject
1. In "Project panel" create new script name it "PlayerController" and add it to player-GameObject

#### Enable both input systems simultaneously:

- This allows you to use both the old UnityEngine.Input class and the new Input System package within the same project.
- Navigate to Edit > Project Settings > Player.
  - Under Other Settings, locate the Active Input Handling setting: Change the value to "Both".

Unity will restart. After the restart, your PlayerController script should function correctly without errors.

#### Basic code to move player version_1

```c#
using UnityEngine;
using System.Collections;

public class PlayerController : MonoBehaviour {

	public float speed = 7;


	// Use this for initialization
	void Start () {



	}

	// Update is called once per frame
	void Update () {

		float inputX = Input.GetAxisRaw ("Horizontal");
		float velocity = inputX * speed;
		transform.Translate (Vector2.right * velocity * Time.deltaTime);

	}
}
```

#### Basic code to move player using camera width, version_2

```c#
using UnityEngine;
using System.Collections;

public class PlayerController : MonoBehaviour {

	public float speed = 7;
	float screenHalfWidthInWorldUnits;

	// Use this for initialization
	void Start () {

		// solving screen wrapping for player
		float halfPlayerWidth = transform.localScale.x / 2f;
		screenHalfWidthInWorldUnits = Camera.main.aspect * Camera.main.orthographicSize + halfPlayerWidth;

	}

	// Update is called once per frame
	void Update () {

		float inputX = Input.GetAxisRaw ("Horizontal");
		float velocity = inputX * speed;
		transform.Translate (Vector2.right * velocity * Time.deltaTime);


	  // if player has gone left edge of the screen
		if (transform.position.x < -screenHalfWidthInWorldUnits) {
			transform.position = new Vector2 (screenHalfWidthInWorldUnits, transform.position.y);
		}

		// if player has gone right edge of the screen
		if (transform.position.x > screenHalfWidthInWorldUnits) {
			transform.position = new Vector2 (-screenHalfWidthInWorldUnits, transform.position.y);
		}

	}
}
```

<br>

### Spawning Random Object

1. Go to GameObject--> 3D Object--> cube, rename it to FallingBlock. Also In Inspector reset all transform.
1. In "Project panel" create new script name it "FallingBlock" and add it to FallingBlock-GameObject

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

1. In "Hierarchy window" select FallingBlock then drag and drop into "Project Window" to make prefab
1. Now In "Hierarchy window" select FallingBlock-gameObject and delete it.
1. Go to GameObject--> "Create Empty" gameObject name it "SpawnManager"
1. In "Project panel" create new script name it "SpawnManager" and add it to SpawnManager-GameObject

```c#
using UnityEngine;
using System.Collections;

public class Spawner : MonoBehaviour {

	public GameObject fallingBlockPrefab;

	// one spawn per second
	public float secondsBetweenSpawns = 1;
	float nextSpawnTime;

	public Vector2 spawnSizeMinMax;
	public float spawnAngleMax;

	// for calculating the screen size in world unit
	Vector2 screenHalfSizeWorldUnits;

	// Use this for initialization
	void Start () {
		// to calculate screen size
		screenHalfSizeWorldUnits = new Vector2 (Camera.main.aspect * Camera.main.orthographicSize, Camera.main.orthographicSize);
	}

	// Update is called once per frame
	void Update () {

		if (Time.time > nextSpawnTime) {
			nextSpawnTime = Time.time + secondsBetweenSpawns;

			float spawnAngle = Random.Range (-spawnAngleMax, spawnAngleMax);
			float spawnSize = Random.Range (spawnSizeMinMax.x, spawnSizeMinMax.y);

			// 1. x axis screen width random, 2. y axis top of screen
			Vector2 spawnPosition = new Vector2 (Random.Range (-screenHalfSizeWorldUnits.x, screenHalfSizeWorldUnits.x), screenHalfSizeWorldUnits.y + spawnSize);

			GameObject newBlock = (GameObject)Instantiate (fallingBlockPrefab, spawnPosition, Quaternion.Euler(Vector3.forward * spawnAngle));

			// scaling the game object
			newBlock.transform.localScale = Vector2.one * spawnSize;
		}

	}
}
```

### Make Falling object destroy player

1. In hierarchy click on player gameObject, then in inspector remove "box collider" component.
1. In hierarchy click on player gameObject add, component--> physic 2D--> "Box Collider 2D"
1. In hierarchy click on player gameObject add, component--> physic 2D--> RigidBody 2D;

   - Rigidbody2D component: ✅ Is Kinematic

<br>

1. In Project click on FallingBlock prefab, then in inspector remove "box collider" component.
1. In Project click on FallingBlock prefab add, component--> physic 2D--> "Box Collider 2D"

   - BoxCollider2D component: ✅ Trigger

1. In Project click on FallingBlock prefab, then in inspector Tag--> add tag--> "Falling Block"
1. In Project click on FallingBlock prefab, then in inspector Tag--> "Falling Block"

1. Open PlayerController.cs and update

```cs

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

// 1️⃣ To destroy player gameobject
	void OnTriggerEnter2D(Collider2D triggerCollider) {
		if (triggerCollider.tag == "Falling Block") {
			Destroy (gameObject);
		}
	}
}
```

### Increase difficulty level by increasing speed of falling block

1. Create a new script name it "Difficulty"

```cs
using UnityEngine;
using System.Collections;

public static class Difficulty {

	static float secondsToMaxDifficulty = 60;

	public static float GetDifficultyPercent() {
		return Mathf.Clamp01(Time.time / secondsToMaxDifficulty);
	}

}
```

1. Update SpawnManager.cs class

```cs
using UnityEngine;
using System.Collections;

public class Spawner : MonoBehaviour {

	public GameObject fallingBlockPrefab;
	public Vector2 secondsBetweenSpawnsMinMax;
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
			// 1️⃣ calculating spawn time
			float secondsBetweenSpawns = Mathf.Lerp (secondsBetweenSpawnsMinMax.y, secondsBetweenSpawnsMinMax.x, Difficulty.GetDifficultyPercent ());
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

1. update FallingBlock.cs

```cs
using UnityEngine;
using System.Collections;

public class FallingBlock : MonoBehaviour {

	public Vector2 speedMinMax;
	float speed;

	void Start() {
		speed = Mathf.Lerp (speedMinMax.x, speedMinMax.y, Difficulty.GetDifficultyPercent ());
	}

	void Update () {
		transform.Translate (Vector3.down * speed * Time.deltaTime, Space.Self);
	}
}

```

1. click on FallingBlock prefab then in inspector "FallingBlock" component: Speed min:7, max: 15

1. Click on SpawnManager gameObject then in

   - SpawnManager component Second between spawn min max: x: 0.1, y:1

#### material

1. Create new folder call it material inside it, right click--> material rename to "player"
   - Component shader: unlit--> color --> **custom color**
1. Drag and drop player-material on player-gameObject
1. Duplicate player-material rename it to "FallingBlock" change its color from inspector
1. Select FallingBlock-prefab then in inspector Material-->element0: FallingBlock

### destroy FallingObject when they get bottom of screen

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
