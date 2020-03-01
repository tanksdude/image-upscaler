#include <Magick++.h>

#include <iostream>
#include <string>

using namespace std;

using namespace Magick;

int main(int argc, char** argv){
	InitializeMagick(*argv); //for Windows users

	std::string filepath;
	int scale;
	bool mspaint;

	//useful: https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/
	if(argc >= 3){
		filepath = argv[1];
		scale = std::stoi(argv[2]);
		scale = (scale > 1 ? scale : 1);
		if(argc >= 4){
			std::string str = argv[3];
			mspaint = (str=="mspaint" || str=="true" || str=="t" || str=="yes" || str=="y");
		} else {
			mspaint = false;
		}
	} else {
		cout << "Enter the filepath: ";
		cin >> filepath;

		do{
			cout << "Enter the scale: ";
			cin >> scale;
			if(scale <= 0){
				cout << "Invalid scale!" << endl;
			}
		} while(scale <= 0);

		mspaint = false; //mspaint is secret
	}

	if(filepath[0] == '\"'){
		//scrub quotes
		filepath = filepath.substr(1, filepath.size() - 2);
	}

	size_t localpath = filepath.find_last_of("/\\"); //checks either '/' or '\\'
	std::string imageName;
	if(localpath != std::string::npos){
		imageName = filepath.substr(localpath+1, filepath.size() - localpath);
	} else {
		imageName = filepath;
	}

	size_t extension = imageName.find_last_of(".");
	std::string modifiedName;
	if(extension != std::string::npos){
		modifiedName = imageName.substr(0, extension) + "-modified" + imageName.substr(extension, imageName.size() - extension);
	}

	//cout << filepath << endl << imageName << endl << modifiedName << endl;

	if(scale == 1){
		cout << "...why? (Image will still be created)" << endl;
	}

	try{
		Image original(filepath);

		if(!mspaint){ //upscale it like a normal person
			Image modified((Geometry)(std::to_string(scale*original.columns()) + "x" + std::to_string(scale*original.rows())), (Color)"transparent");

			for(int x = 0; x < original.columns(); x++){ //main image
				for(int y = 0; y < original.rows(); y++){
					
					for(int i = 0; i < scale; i++){ //pixel blocks
						for(int j = 0; j < scale; j++){
							modified.pixelColor(x*scale + i, y*scale + j, original.pixelColor(x, y));
						}
					}

				}
			}
			//apparently box or point resizing filters do this, except faster...

			//ugly upscaling
			//original.resize(std::to_string(scale*original.columns()) + "x" + std::to_string(scale*original.rows()));

			modified.write(modifiedName);

		} else { //mspaint-ify it like a memer
			Image modified1 = original;
			modified1.resize(std::to_string(int((1.0/scale)*original.columns())) + "x" + std::to_string(int((1.0/scale)*original.rows())));
			Image modified2((Geometry)(std::to_string(scale*modified1.columns()) + "x" + std::to_string(scale*modified1.rows())), (Color)"transparent");
			
			for(int x = 0; x < modified1.columns(); x++){ //main image
				for(int y = 0; y < modified1.rows(); y++){
					
					for(int i = 0; i < scale; i++){ //pixel blocks
						for(int j = 0; j < scale; j++){
							modified2.pixelColor(x*scale + i, y*scale + j, modified1.pixelColor(x, y));
						}
					}

				}
			}

			modified2.write(modifiedName);
		}

		cout << "Finished! Exiting..." << endl;
	}
	catch(exception &e){
		cout << "Caught exception: " << e.what() << endl;
		return 1;
	}

	return 0;
}