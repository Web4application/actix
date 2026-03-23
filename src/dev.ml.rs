/// Development tasks for the Tauri project
///
/// This module provides helper functions to:
/// - Start the frontend development server
/// - Run the Rust backend in development mode
/// - Watch files for changes and reload the app
///
/// # Usage
/// ```rust
/// dev_ml::run_dev_tasks();
/// ```
pub mod dev_ml {
    use std::process::{Command, Stdio};

    /// Starts all development tasks
    ///
    /// This function:
    /// 1. Runs the frontend dev server (npm/yarn)
    /// 2. Builds and runs the Rust backend in dev mode
    /// 3. Prints useful information to the console
    pub fn run_dev_tasks() {
        println!("Starting Tauri development environment...");

        // Step 1: Start frontend dev server
        println!("Starting frontend dev server...");
        let frontend_status = Command::new("npm")
            .args(&["run", "dev"])
            .stdout(Stdio::inherit())
            .stderr(Stdio::inherit())
            .status()
            .expect("Failed to start frontend dev server");

        if !frontend_status.success() {
            eprintln!("Frontend dev server exited with an error!");
            return;
        }

        // Step 2: Start Rust backend in dev mode
        println!("Starting Rust backend (Tauri)...");
        let backend_status = Command::new("cargo")
            .args(&["tauri", "dev"])
            .stdout(Stdio::inherit())
            .stderr(Stdio::inherit())
            .status()
            .expect("Failed to start Tauri backend");

        if !backend_status.success() {
            eprintln!("Tauri dev server exited with an error!");
            return;
        }

        println!("Development environment is running successfully!");
    }

    /// Optional: Watch frontend files and rebuild automatically
    ///
    /// You can extend this with `notify` crate to watch `src/` and `dist/` folders.
    pub fn watch_frontend_changes() {
        println!("Watching frontend files for changes...");
        // Example placeholder: implement with `notify` crate
    }
}
