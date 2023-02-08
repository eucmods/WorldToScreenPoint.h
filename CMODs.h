//32BITS
Vector3 WorldToScreenPoint(Vector3 test) {
	  Vector3 position;
	  static const auto WorldToScreenPoint_Injected = reinterpret_cast<uint64_t(*)(void *,Vector3, int, Vector3 &)>(getAbsoluteAddress("libil2cpp.so", 0xF39264));
      WorldToScreenPoint_Injected(get_main(), test, 4, position);
      return position;
}

//64BITS
Vector3 WorldToScreenPoint(void *transform, Vector3 test) {
    if (!transform)return Vector3();
    Vector3 position;
    static const auto WorldToScreenPoint_Injected = reinterpret_cast<uint64_t(__fastcall *)(void *,Vector3, int, Vector3 &)>(getAbsoluteAddress("libil2cpp.so", 0xF39264 ));//public sealed class Camera //private void WorldToScreenPoint_Injected(ref Vector3 position, Camera.MonoOrStereoscopicEye eye, out Vector3 ret) { }
      WorldToScreenPoint_Injected(transform, test, 4, position);
      return position;
}



If you want without the need to : reinterpret_cast<uint64_t
use the yes : void (*WorldToScreenPoint_Injected)(void *, Vector3, int, Vector3&)

Use on your own.
