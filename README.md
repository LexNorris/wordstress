
# Wordstress dictionary v1.0.0 #

This dictionary project was born out of necessesity and finished out of passion. I may well be the only person who will ever use this project due to its limited scope, but I expect it will make my life easier.
Udates will implement a handful of new features. Including:
adding words from a binary file. Multiple users (should there be any) can put their combined dictionaries together and eventually a larger database can be created.

## Purpose ##

### Backstory ###
In 2021 I began to write in iambic for certain characters.

The beginnings of this journey sent me to the dictionary often. A single line could take me hours of my life between the time I spent to navigate the dictionary site and words I had to search repeatedly. Now I find it easy to both speak and write this way, but those were darker times. To solve the issues which I had of excess information, need for internet, and searches which repeat I figured I could write a program to provide some simple information.

The word. The patterned stress. And that was it.

Do not come here in search of definitions. Do not come here in search of usage explanations. Do not come here in search of synonyms. A million other apps exist for that, but still I had no patterns. Save the dictionary site I grew to loathe.

While now I simply hear the melody of words and know the pattern like the Bard once did, I give to you this uncompleted project born in need. Born again with love.

Sappiness aside this is a project which I feel that I am close to.
However, though, I think there are some problems with this thing. It lacks in error checking -  after that it lacks some functionality. But it works for now.


## Currently implemented methods ##

### Search ###

stress -s *word*

A user can search for a word and if said word exists in the dictionary files, the program will return the stress pattern(s) of the word to be searched.

### Add (single word) ###

stress -a *# of stress patterns* *word* *stress pattern1* *stress pattern3* ...

This adds a single word to the dictionary files. If you mess up on the stress patterns, simply overwrite with add again.
If you mess up on the word itself it's there forever until I can implement delete.

### Add (multiple words) ###
stress -r *# of words* *1st word # stress patterns* *word* *1 stress pattern1* *1 stress pattern 2*... *2nd word # of stress patterns* *word* *2 word stress pattern1*...

-r refers to recursive. This did not happen, but I am too lazy to change the command right now.

### Add (from text file) ###

stress -f *filename.txt*

This function accepts a text file in the following format
*# of stress patterns* *word* *stress pattern 1* *stress pattern 2* ...
*# of stress patterns* *word* *stress pattern 1* *stress pattern 2*...
.
.
.

Keep in mind that I do not have error checking for expected inputs *yet.* My goal is to have the program iterate through and check that the letters input to the stress patterns are all S, u, and s. Then to have it check the format of the given line. For now, please don't bork it on purpose. Thank you.

### Add (from bin file) (Coming soon) ###

stress -f *letter.bin*

The program will recognize the .bin or .txt extension and react appropriately.

### Delete ###

stress -d *word*

The program should read in the file, find the word you want to remove and then conveniently not place it in the search tree.

### Help ###

stress -help

Exactly as it sounds. Having trouble? USe it.


