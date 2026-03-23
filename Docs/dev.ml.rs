/// Development tasks for Tauri project
///
/// This module provides helper commands to:
/// - Start frontend dev server
/// - Run the Rust app in dev mode
/// - Watch files for changes
pub fn run_dev_tasks() {
    println!("Starting development tasks...");

    // Example: start frontend dev server
    std::process::Command::new("npm")
        .args(&["run", "dev"])
        .status()
        .expect("Failed to start frontend dev server");

    println!("Rust dev server is running...");
}
