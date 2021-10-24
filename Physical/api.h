#ifdef PHYSICAL_EXPORTS
#define PHYSICAL_API __declspec(dllexport)
#else
#define PHYSICAL_API __declspec(dllimport)
#endif
