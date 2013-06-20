/*
Copyright (c) 2013, Gareth Richardson
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies,
either expressed or implied, of the FreeBSD Project.
*/

/*
	file name:		file.hpp
	date created:	21/06/2013
	date updated:	21/06/2013
	author:			Gareth Richardson
	description:	This is the header file for the class File. This is the class used
					to find and load a file into memory for use with the BlueBasic engine.
*/

/*
	values for the errorFlag:
*/
#define LOCATION_ERROR 0x00ff
#define CHARACTER_ERROR 0xff00

/*
	We define the amount of bytes in a Megabyte here, use this to define the Maximum size of
	the resverved memory for a file.
*/
#define MEGABYTE 1024 * 1024

/*
	A pre-processor defining the maximum amount of characters that can be put into
	the memory. Adjust accordingly.
	Add more megabyte like this:
	*if you want 3 megabytes reserved, you type:
	MAX_SIZE (MEGABYTE * 3)
	Warning: 2 Megabytes or more crash a Windows system. Maybe stick it to just a megabyte
	of memory for a file.
*/
#define MAX_SIZE (MEGABYTE * 1)

class File {
	private:
		/*
			This is the name of the file, inculding the directory location it is at.
		*/
		string fileName;
		/*
			All errors are saved here as a bit flag.
			0x0000 :: no errors
			0x00ff :: file not found
			0xff00 :: invalid character found
		*/
		short errorFlag;
		
		/*
			The entire file in memory:
		*/
		char fileInMemory[MAX_SIZE];
		
		/*
			The location of the character that is going to be read next.
		*/
		int index;
		
		/*
			The size of the file that has just been put into memory
		*/
		int fileSize;
		
		/*
			initialisation code here:
		*/
		void init();
	public:
		File();
		File(string value);
		
		/*
			Checks if the fiel has been found or not
		*/
		bool foundFile();
		
		/*
			Checks if the end of the file has been reached.
		*/
		bool endOfFile();
		
		/*
			Gets the character and sets the object up to get the next cahracter from memory
		*/
		char getCharacter();
};

