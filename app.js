// 1. Data Store: The phrases that will cycle on screen
const words = ["new tech stacks.", "Web Development.", "Embedded Systems.", "Problem Solving."];
let wordIndex = 0;
let charIndex = 0;
let isDeleting = false;

function typeEffect() {
    // 2. DOM Selection: Find our HTML target span
    const typewriterSpan = document.getElementById("typewriter");
    const currentWord = words[wordIndex];

    // 3. String Manipulation: Determine how many characters to show
    if (isDeleting) {
        // Take a shorter substring to simulate deleting
        typewriterSpan.textContent = currentWord.substring(0, charIndex - 1);
        charIndex--;
    } else {
        // Take a longer substring to simulate typing
        typewriterSpan.textContent = currentWord.substring(0, charIndex + 1);
        charIndex++;
    }

    // 4. Dynamic Timing Engine
    let typeSpeed = 100; // Normal typing speed (milliseconds)

    if (isDeleting) {
        typeSpeed /= 2; // Delete twice as fast as typing
    }

    // Checking if a single word is fully typed out
    if (!isDeleting && charIndex === currentWord.length) {
        typeSpeed = 1500; // Pause for 1.5 seconds when word is complete
        isDeleting = true;
    } 
    // Checking if a single word is completely deleted
    else if (isDeleting && charIndex === 0) {
        isDeleting = false;
        // The Modulo operator (%) safely resets the index back to 0 when we reach the end of the array
        wordIndex = (wordIndex + 1) % words.length; 
        typeSpeed = 500; // Brief pause before starting to type the next word
    }

    // 5. Recursion Loop: Call this exact function again after 'typeSpeed' milliseconds
    setTimeout(typeEffect, typeSpeed);
}

// Start the entire typing effect animation once the webpage finishes loading
document.addEventListener("DOMContentLoaded", typeEffect);