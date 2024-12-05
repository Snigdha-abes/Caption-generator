const itemForm = document.getElementById("item-form");
const itemInput = document.getElementById("item-input");
const itemList = document.getElementById("item-list");
const clearBtn = document.getElementById("clear");
const itemFilter = document.getElementById("filter");
const formBtn = itemForm.querySelector('button'); // Correct reference to the button in the form
let isEditMode = false;

const Filterbtn = document.getElementById("filter");

function addItem(e) {
    e.preventDefault();
    const newItem = itemInput.value.trim();

    // Validate the input field
    if (newItem === '') {
        alert("Please enter some value");
        return;
    }

    if (isEditMode) {
        // Edit the item
        itemToEdit.firstChild.textContent = newItem;
        isEditMode = false;
        itemToEdit.classList.remove('edit-mode');
        itemToEdit = null;
        formBtn.innerHTML = '<i class="fa-solid fa-plus"></i> Add Item';
        formBtn.style.backgroundColor = "";
    } else {
        // Create list-item
        const li = document.createElement('li');
        li.appendChild(document.createTextNode(newItem));
        const button = createBtn("remove-item btn-link text-red");
        li.appendChild(button);

        // Append the new list item to the list
        itemList.appendChild(li);
    }

    // Clear the input field and check UI
    itemInput.value = '';
    checkUI();
}

// Helper function to create a button element with specified classes
function createBtn(classes) {
    const button = document.createElement('button');
    button.className = classes; // Set the button's class attribute
    const icon = createIcon("fa-solid fa-xmark"); // Create a remove icon for the button
    button.appendChild(icon); // Append the icon to the button
    return button; // Return the created button element
}

// Helper function to create an icon element with specified classes
function createIcon(classes) {
    const icon = document.createElement('i');
    icon.className = classes; // Set the icon's class attribute
    return icon; // Return the created icon element
}

// Function to check and adjust the UI based on the current state (e.g., whether the list is empty)
function checkUI() {
    if (itemList.children.length === 0) { // Check if the list is empty
        clearBtn.style.display = 'none'; // Hide the clear button
        Filterbtn.style.display = 'none'; // Hide the filter input field
    } else {
        clearBtn.style.display = 'block'; // Show the clear button
        Filterbtn.style.display = 'block'; // Show the filter input field
    }
}

// Function to remove an item from the list or set it to edit mode
function removeItem(e) {
    if (e.target.parentElement.classList.contains('remove-item')) { // Check if the clicked element is a remove button
        e.target.parentElement.parentElement.remove(); // Remove the parent list item of the clicked remove button
        checkUI(); // Check and adjust the UI after removing the item
    } else {
        setItemToEdit(e.target.parentElement); // Pass the correct element to setItemToEdit
    }
}

// Function to set an item to edit mode
function setItemToEdit(item) {
    isEditMode = true;
    itemToEdit = item;
    // Ensure only the item being edited has the 'edit-mode' class
    itemList.querySelectorAll('li').forEach(i => i.classList.remove('edit-mode'));
    item.classList.add('edit-mode');
    formBtn.innerHTML = '<i class="fa-solid fa-pen"></i> Update Item';
    formBtn.style.backgroundColor = "#228B22";
    itemInput.value = item.firstChild.textContent; // Set the input value to the item text
}

// Function to clear all items from the list
function clearItems() {
    while (itemList.firstChild) { // Loop through all child elements of the list
        itemList.removeChild(itemList.firstChild); // Remove each child element (list item)
    }
    checkUI(); // Check and adjust the UI after clearing all items
}

// Function to filter items in the list based on the text entered in the filter input field
function filterItems(e) {
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

// Event-listener
itemForm.addEventListener('submit', addItem);
itemList.addEventListener('click', removeItem);
clearBtn.addEventListener('click', clearItems);
itemFilter.addEventListener('input', filterItems);

localStorage.setItem('name', 'Snow');
console.log(localStorage.getItem('name'));
localStorage.removeItem('name');
