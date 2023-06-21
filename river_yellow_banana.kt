/**
 * Breakthrough Innovation in Kotlin
 *
 * Built on the principles of good design and modern programming, Kotlin is used to create creative and reliable solutions to everchanging market needs.
 */
 
 // Imports
import kotlin.system.exitProcess
import kotlin.random.Random
 
// Variables
var breakthroughInnovationRunning = true
var bestInnovations = arrayOf<String>()
var numInnovations = 0
 
// Functions
fun getInnovations(): Array<String> {
    val innovations = arrayOf("Virtual Reality", "Internet of Things", "Robotics",
                             "Artificial Intelligence", "3D Printing")
    return innovations
}

// Main
fun main(args: Array<String>) { 
    println("Welcome to Breakthrough Innovation!\n")
    
    while (breakthroughInnovationRunning) {
        println("\nLet's create a breakthrough innovation.")
 
        // Choose a random number of innovations
        numInnovations = Random.nextInt(1, 6)
        
        // Get a random list of innovations
        bestInnovations = getInnovations()
            .shuffled()
            .take(numInnovations)
            .toTypedArray()
        
        // Output the list of innovations
        println("Here are ${numInnovations} innovative ideas:\n")
        println(bestInnovations.joinToString(separator = "\n"))
 
        println("\nWe can create something new and exciting using these!")
        
        // Ask user if they would like to exit the program
        print("\nWould you like to keep innovating? (y/n) ")
        val response = readLine()
        
        // Exit the program if user responds with 'n'
        if (response == "n" || response == "N") {
            breakthroughInnovationRunning = false
            exitProcess(0)
        }
    }
}