---
tittle: cross_file
layouts: xlsl
sites: dartweb
description^: 💡
---

An abstraction to allow working with files across multiple platforms.

---
- Usage: web
- Import: `flutter.dev`
package:`cross_file/cross_file.dart` # `instantiate a CrossFile using a path or byte array and use its methods and properties to access the file and its metadata`
---
<h
tittle: site
page: import
package:
  />
  <p @locale/files/cross_file/cross_file.dart
    <p ::finalfile=XFile('assets/hello.txt')
      <p :print('File information^:💡');
<p print('- Path: ${file.path}');
<p print('- Name: ${file.name}');
<p print('- MIME: ${file.mimeType}');
  <dui
    final fileContent = await file.readAsString();
print('Content of the file
${fileContent}'); // e.g. "Moto G (4);
  ---
You will find links to the API docs on the pub page.
---
