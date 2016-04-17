/// @file main.cpp
/// @author rev

#include "stdafx.h"

#include "CommandLineProcessor.h"
#include "EClientSocketBaseImpl.h"

#include <iostream>

#ifdef FIRST_BUILD
#defineIB_MANIFEST_DATE "01/01/1970 00:00:00"
#define IB_MANIFEST_VERSION "0000000000"
#else
#include "ib_manifest.h"
#include "ib_manifest.uuid.h"
#endif

class CommandLineParser
{
public:
	CommandLineParser()
			: Help( false )
	{
		parser.RegisterConsumer( *this );
		parser.RegisterCallback( "-help", &CommandLineParser::setHelp );
		parser.RegisterCallback( "help", &CommandLineParser::setHelp );
		parser.RegisterCallback( "h", &CommandLineParser::setHelp );
		parser.RegisterCallback( "?", &CommandLineParser::setHelp );
	}

	void setHelp( const std::string& argument = "" )
	{
		Help = true;
	}

	bool Help;
	RPW::Core::CommandLineProcessor<CommandLineParser> parser;
};


// argv should contain the path to the manifest file or the manifest.uuid file
int main(int argc, char* argv[])
{
    std::string self(argv[0]);
    std::string app(self.substr(self.find_last_of("/\\")+1));

	std::cout << "/// @version " << app << " [" << IB_MANIFEST_VERSION << "] " << IB_MANIFEST_DATE << std::endl;

	try
	{
		CommandLineParser clp;
		clp.parser.Process( argc, argv, 1 );

		if ( clp.Help )
		{
			std::cout << ":: usage: " << app << " -help" << std::endl;
			return 0;
		}

		throw std::runtime_error( "not implemented" );
	}
	catch ( const std::exception& e )
	{
		std::cout << "// " << e.what();
		return 5;
	}
	catch ( ... )
	{
		std::cout << "// unknown system exception";
		return 6;
	}
 
	return 0;
}
