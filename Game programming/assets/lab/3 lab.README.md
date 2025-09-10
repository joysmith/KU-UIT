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

```c#
using UnityEngine;
using System.Collections;

public class PlayerController : MonoBehaviour {

	public float speed = 7;
	float screenHalfWidthInWorldUnits;

	// Use this for initialization
	void Start () {



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
