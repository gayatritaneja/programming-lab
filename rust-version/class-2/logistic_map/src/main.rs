use sysinfo::{System, Components};

fn main() {
    // Initialize system
    let mut sys = System::new();
    sys.refresh_components();

    // sysinfo stores temperature sensors as "components"
    let components = Components::new_with_refreshed(&mut sys);

    // default fallback
    let mut cpu_temp_c = 50.0;

    // Look for a component whose label contains "cpu"
    for c in components {
        let label = c.label().to_lowercase();

        if label.contains("cpu") || label.contains("core") {
            cpu_temp_c = c.temperature();
            break;
        }
    }

    println!("CPU Temperature: {}°C", cpu_temp_c);

    // Normalize 0–100 → 0–1
    let mut x = (cpu_temp_c / 100.0).clamp(0.0, 1.0);

    println!("Normalized initial x: {}", x);

    // logistic map parameter
    let r: f64 = 3.8;

    // Iterate logistic map
    for _ in 0..1000 {
        x = r * x * (1.0 - x);
        println!("{}", x);
    }
}
