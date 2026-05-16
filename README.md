# gdiplus for tcc portable
This package (gp4tp) provides gdiplus headers, related winapi headers completion and a compatible header for default [Tiny C Compiler](https://www.bellard.org/tcc/).

The package contains following parts:
- **gdiplus.h** : a compatible header for Tiny C Compiler.
- **gdiplus** : a part of the w32api package.
- **winapigp** : a part of the w64 mingw-runtime package, with few includes modified to local include for portability.

### Usage

1. Copy the whole package into the project.
2. Add `#include "gp4tp/gdiplus.h"` directly in the start of the code file.

### Example

```c
#include <stdlib.h>
#include "gp4tp/gdiplus.h"

int main(int argc, char *argv[]){
	ULONG_PTR token;
	GdiplusStartupInput gsi = { 1, };
	GdiplusStartup(&token, &gsi, NULL);
	
	GpBitmap *bmp;
	// prepare an external image file
	GdipCreateBitmapFromFile(L"test.png", &bmp);
	
	GpGraphics *g;
	GdipGetImageGraphicsContext(bmp,&g);
	
	GpPen* pen;
	GdipCreatePen1(0xff00aaff,2,UnitWorld,&pen);
	GdipDrawRectangle(g,pen,10.0,40.0,100.0,80.0);
	GdipDeletePen(pen);
	
	
	// save image in specific format
	
	UINT num = 0;     // number of image encoders 
	UINT size = 0;    // size of the image encoder array in bytes 
	GdipGetImageEncodersSize(&num, &size);
	
	ImageCodecInfo* pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	GdipGetImageEncoders(num, size, pImageCodecInfo);
	
	// Encoder index:{Bmp,Jpeg,Gif,Tiff,Png}
	GdipSaveImageToFile(bmp, L"output.png", pImageCodecInfo[4].Clsid, NULL);
	free(pImageCodecInfo);
	
	
	GdipDisposeImage(bmp);
	GdipDeleteGraphics(g);
	
	
	GdiplusShutdown(token);
	return 0;
}
```

### Tips

You can directly search and find the way to use gdi+ api inside `gdiplus` headers, just like example codes.

1. Search the function you need to use.
2. Find classes related to the function.
3. Search the constructor (and the destructor) of the classes.
4. Recursively figure out how to create, use, delete every type the function or related classes needs.