# 1. Implement 3D transformations (Translation, Rotation, Scaling) on a simple object using OpenGL or DirectX or Unity3D

1. Open unity Hub create a new project--> universal 3d--> create
1. In "Scene mode" switch to isometric view, Top view
1. In Hierarchy window select "Main camera" gameObject, Then in Inspector, in Camera Component
   Projection: Orthographic
   Environment--> Background type: Solid type
1. Go to GameObject--> 3D Object--> Cube, rename it to player. Also In Inspector reset all transform
1. In "project Window" create new C# script, name it to "Player_controller"
1. In Hierarchy window select "Player" GameObject, then in inspector **add Component** "Player_controller" script.
1. Now open "Player_Controller.cs" with any IDE and write code

### GameObject Translation

[Translation](https://docs.unity3d.com/ScriptReference/Transform.Translate.html) (Position): To move an object, modify its position property or use the Translate method.

```c#
using UnityEngine;

public class ObjectMover : MonoBehaviour
{
    public float moveSpeed = 1f;
    // [SerializeField] public float moveSpeed = 1f;

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

### GameObject Rotation

Rotation: [Rotation](https://docs.unity3d.com/ScriptReference/Transform.Rotate.html) can be achieved by modifying the rotation or localRotation properties (using Quaternions), or by using the Rotate method (using Euler angles).

```c#
using UnityEngine;

public class ObjectRotator : MonoBehaviour
{
    public float rotationSpeed = 50f;

    void Update()
    {
        // Option 1: Rotate using Euler angles (simpler for direct input)
        // Rotates around the object's local Y-axis
        transform.Rotate(0, rotationSpeed * Time.deltaTime, 0, Space.Self);

        // Option 2: Set rotation using Quaternions (more robust for complex rotations)
        // transform.rotation = Quaternion.Euler(0, rotationSpeed * Time.deltaTime, 0);
    }
}
```

### GameObject Scaling

[Scaling](https://docs.unity3d.com/ScriptReference/Transform-localScale.html): To change the size of an object, modify its localScale property.

```c#
using UnityEngine;

public class ObjectScaler : MonoBehaviour
{
    public float scaleSpeed = 0.1f;
    private bool increasing = true;

    void Update()
    {
        if (increasing)
        {
            transform.localScale += new Vector3(scaleSpeed * Time.deltaTime, scaleSpeed * Time.deltaTime, scaleSpeed * Time.deltaTime);
            if (transform.localScale.x >= 2f) increasing = false;
        }
        else
        {
            transform.localScale -= new Vector3(scaleSpeed * Time.deltaTime, scaleSpeed * Time.deltaTime, scaleSpeed * Time.deltaTime);
            if (transform.localScale.x <= 0.5f) increasing = true;
        }
    }
}
```
