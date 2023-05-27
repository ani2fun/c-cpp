plugins {
    // Apply the cpp-application plugin to add support for building C & C++ executables
    `cpp-application`
}

// Set the target operating system and architecture for this application
application {
    targetMachines.add(machines.macOS.architecture("aarch64"))
}
