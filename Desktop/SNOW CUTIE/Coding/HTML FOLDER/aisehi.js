// Function to add a new item to the list
function addItem(e) {
    e.preventDefault(); // Prevent the default form submission behavior
    newItem = itemInput.value; // Get the value entered in the input field

    // Validate the input field
    if (newItem === '') {
        alert("Please enter some value");
        return; // Exit the function if the input is empty
    }

    // Create a new list item element
    const li = document.createElement('li');
    li.appendChild(document.createTextNode(newItem)); // Add the entered text as a text node to the list item

    // Create a remove button for the new item
    const button = createbtn("remove-item btn-link text-red");
    li.appendChild(button);

    // Check and adjust the UI based on the current state
    CheckUI();

    // Append the new list item to the list
    itemList.appendChild(li);

    // Clear the input field after adding the item
    itemInput.value = '';
}

// Helper function to create a button element with specified classes
function createbtn(classes) {
    const button = document.createElement('button');
    button.className = classes; // Set the button's class attribute
    const icon = createicon("fa-solid fa-xmark"); // Create a remove icon for the button
    button.appendChild(icon); // Append the icon to the button
    return button; // Return the created button element
}

// Helper function to create an icon element with specified classes
function createicon(classes) {
    const icon = document.createElement('i');
    icon.className = classes; // Set the icon's class attribute
    return icon; // Return the created icon element
}

// Function to check and adjust the UI based on the current state (e.g., whether the list is empty)
function CheckUI() {
    if (itemList.children.length === 0) { // Check if the list is empty
        clearBtn.style.display = 'none'; // Hide the clear button
        Filterbtn.style.display = 'none'; // Hide the filter input field
    } else {
        clearBtn.style.display = 'block'; // Show the clear button
        Filterbtn.style.display = 'block'; // Show the filter input field
    }
}

// Function to remove an item from the list
function removeItem(e) {
    if (e.target.parentElement.classList.contains('remove-item')) { // Check if the clicked element is a remove button
        e.target.parentElement.parentElement.remove(); // Remove the parent list item of the clicked remove button
        CheckUI(); // Check and adjust the UI after removing the item
    }
}

// Function to clear all items from the list
function clearItems() {
    while (itemList.firstChild) { // Loop through all child elements of the list
        itemList.removeChild(itemList.firstChild); // Remove each child element (list item)
    }
    CheckUI(); // Check and adjust the UI after clearing all items
}

// Function to filter items in the list based on the text entered in the filter input field
function filteritems(e) {
    const items = itemList.querySelectorAll('li'); // Get all list items in the list
    const text = e.target.value.toLowerCase(); // Get the filter text entered by the user
    items.forEach((item) => { // Loop through each list item
        const itemName = item.firstChild.textContent.toLowerCase(); // Get the text content of the list item
        // Check if the filter text is found in the item name
        if (itemName.indexOf(text) !== -1) {
            item.style.display = 'flex'; // Show the item
        } else {
            item.style.display = 'none'; // Hide the item
        }
    });
}
