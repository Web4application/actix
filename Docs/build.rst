:Build Guide: .. toctree:
   :maxdepth: 2

   build
   dev
===========

This guide explains how to build and package your Tauri application, including CI/CD workflows.

:Requirements:
------------

Ensure you have the following installed:
.. https://docs.rs:
:- Rust (latest stable): https://rustup.rs
- Node.js (LTS): https://nodejs.org
- Cargo (comes with Rust)
 :- Tauri CLI: com.actix.app

  .. code-block:: bash

     cargo install tauri-cli

Platform-specific dependencies:

- Linux: webkit2gtk, libappindicator
- macOS: Xcode Command Line Tools
- Windows: Microsoft Visual Studio (C++ build tools)

:Project Setup:
-------------

Clone the repository and install dependencies:

.. code-block:: bash

   git clone https://github.com/web4application/actix.git
   cd actix
   npm install

:Development Build:  .. toctree:
-----------------

To run the app in development mode:

.. code-block:: bash

   npm run tauri dev

.. This will:

- Start the frontend dev server
- Launch the Tauri app for live testing

:Production Build: .. toctree:
   :maxdepth: 2

   build
   dev
----------------

### Step 1: Build the frontend

.. code-block:: bash

   npm run build

> This creates the static frontend assets (HTML, JS, CSS) in your configured `frontendDist` folder.

### Step 2: Build the Tauri application

.. code-block:: bash

   npx tauri build

.. This command:

- Compiles the Rust backend
- Bundles the frontend assets
- Generates platform-specific installable packages

:Output:
------

After building, artifacts are located in:

- ```src-tauri/target/release/``` — application binary
- ``src-tauri/target/release/bundle/`` — installers (MSI, DMG, AppImage, etc.)

:Bundle Formats: .. toctree:
   :maxdepth: 2

   build
   dev
--------------

Depending on your platform:

- Windows: ``.msi``, ``.exe``
- macOS: ``.dmg``, ``.app``
- Linux: ``.AppImage``, ``.deb``, ``.rpm``

:Configuration:
-------------

The build uses ```src-tauri/tauri.conf.json```:

Important fields:

- ``build.frontendDist`` → folder containing frontend build assets
- ``build.beforeBuildCommand`` → command executed before build (usually builds frontend)
- ``bundle.identifier`` → unique application identifier

Example ``tauri.conf.json`` snippet:

.. code-block:: json

   {
     "build": {
       "beforeBuildCommand": "npm run build",
       "frontendDist": "../dist"
     },
     "bundle": {
       "identifier": "com.yourcompany.app"
     }
   }

:Common Issues:
-------------

.. Frontend not found: .. toctree::
   :maxdepth: 2

   build
   dev

- Ensure ``npm run build`` is executed before `tauri build`
- Verify `frontendDist` path exists

### :Version mismatch:

- Ensure Tauri frontend and backend packages match:

  .. code-block:: bash

     npm install @tauri-apps/api@latest
     cargo update

### Invalid bundle identifier

- Do not use ``com.tauri.dev``
- Use a unique identifier:

  ``com.actix.app``

:Clean Build:
-----------

If you encounter build errors:

.. code-block:: bash

   cargo clean
   npm install
   npm run build
   npx tauri build

:CI/CD Integration:
----------------

To automate builds in CI/CD pipelines:

1. Install Rust, Node.js, and Tauri CLI
2. Run the same build steps in your pipeline:

.. code-block:: bash

   npm ci
   npm run build
   npx tauri build --ci

> The `--ci` flag skips interactive prompts, which is useful for automated pipelines.

:Optional:

- Sign binaries (macOS/Windows) if needed
- Upload artifacts to release servers

---

:Tips: .. toctree:
   :maxdepth: 2

   build
   dev


- Always verify ``frontendDist`` points to the correct build folder
- Use version control for ``tauri.conf.json`` and CI/CD scripts
- Keep Rust and Node.js up to date for 
:smoother builds:

.. toctree:
   :maxdepth: 2

   build
   dev
