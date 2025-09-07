# 1. Implement 3D transformations (Translation, Rotation, Scaling) on a simple object using OpenGL or DirectX or Unity3D

1. Open unity Hub create a new project--> universal 3d--> create
1. In "Scene mode" switch to isometric view, Top view
1. In Hierarchy window select "Main camera" gameObject, Then in Inspector, in Camera Component: Environment--> Background type: Solid type
1. Go to GameObject--> 3D Object--> Cube, rename it to player. Also In Inspector reset all transform
1. In "project Window" create new C# script, name it to "Player_controller"
1. In Hierarchy window select "Player" GameObject, then in inspector **add Component** "Player_controller" script.
1. Now open "Player_Controller.cs" with any IDE and write code

#### Translation

```c#
using UnityEngine;

public class ObjectMover : MonoBehaviour
{
    public float moveSpeed = 1f;

    void Update()
    {
        // Option 1: Directly modify position
        // This moves the object in world space
        transform.position += new Vector3(moveSpeed * Time.deltaTime, 0, 0);

        // Option 2: Use Translate method
        // This moves the object relative to its local axes by default, or world axes if Space.World is specified
        // transform.Translate(Vector3.forward * moveSpeed * Time.deltaTime, Space.Self);
    }
}
```
