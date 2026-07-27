#include <raylib.h>

#undef NDEBUG
#include <assert.h>

int main (void)
{
  SetRandomSeed (1);
  assert (GetRandomValue (5, 5) == 5);
  assert (TextIsEqual ("raylib", "raylib"));
  assert (TextLength (RAYLIB_VERSION) > 0);
  return 0;
}
