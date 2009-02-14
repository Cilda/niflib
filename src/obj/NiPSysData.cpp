/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiPSysData.h"
#include "../../include/gen/ParticleDesc.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysData::TYPE("NiPSysData", &NiRotatingParticlesData::TYPE );

NiPSysData::NiPSysData() : hasUnknownFloats3(false), unknownShort1((unsigned short)0), unknownShort2((unsigned short)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiPSysData::~NiPSysData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiPSysData::GetType() const {
	return TYPE;
}

NiObject * NiPSysData::Create() {
	return new NiPSysData;
}

void NiPSysData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiRotatingParticlesData::Read( in, link_stack, info );
	if ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) {
		particleDescriptions.resize(numVertices);
		for (unsigned int i2 = 0; i2 < particleDescriptions.size(); i2++) {
			NifStream( particleDescriptions[i2].translation, in, info );
			if ( info.version <= 0x0A040001 ) {
				for (unsigned int i4 = 0; i4 < 3; i4++) {
					NifStream( particleDescriptions[i2].unknownFloats1[i4], in, info );
				};
			};
			NifStream( particleDescriptions[i2].unknownFloat1, in, info );
			NifStream( particleDescriptions[i2].unknownFloat2, in, info );
			NifStream( particleDescriptions[i2].unknownFloat3, in, info );
			NifStream( particleDescriptions[i2].unknownInt1, in, info );
		};
	};
	if ( ( info.version >= 0x14000004 ) && ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) ) {
		NifStream( hasUnknownFloats3, in, info );
		if ( (hasUnknownFloats3 != 0) ) {
			unknownFloats3.resize(numVertices);
			for (unsigned int i3 = 0; i3 < unknownFloats3.size(); i3++) {
				NifStream( unknownFloats3[i3], in, info );
			};
		};
	};
	if ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) {
		NifStream( unknownShort1, in, info );
		NifStream( unknownShort2, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiRotatingParticlesData::Write( out, link_map, info );
	if ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) {
		for (unsigned int i2 = 0; i2 < particleDescriptions.size(); i2++) {
			NifStream( particleDescriptions[i2].translation, out, info );
			if ( info.version <= 0x0A040001 ) {
				for (unsigned int i4 = 0; i4 < 3; i4++) {
					NifStream( particleDescriptions[i2].unknownFloats1[i4], out, info );
				};
			};
			NifStream( particleDescriptions[i2].unknownFloat1, out, info );
			NifStream( particleDescriptions[i2].unknownFloat2, out, info );
			NifStream( particleDescriptions[i2].unknownFloat3, out, info );
			NifStream( particleDescriptions[i2].unknownInt1, out, info );
		};
	};
	if ( ( info.version >= 0x14000004 ) && ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) ) {
		NifStream( hasUnknownFloats3, out, info );
		if ( (hasUnknownFloats3 != 0) ) {
			for (unsigned int i3 = 0; i3 < unknownFloats3.size(); i3++) {
				NifStream( unknownFloats3[i3], out, info );
			};
		};
	};
	if ( (!((info.version >= 0x14020007) && (info.userVersion == 11))) ) {
		NifStream( unknownShort1, out, info );
		NifStream( unknownShort2, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiPSysData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiRotatingParticlesData::asString();
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < particleDescriptions.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Translation:  " << particleDescriptions[i1].translation << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Floats 1[" << i2 << "]:  " << particleDescriptions[i1].unknownFloats1[i2] << endl;
			array_output_count++;
		};
		out << "    Unknown Float 1:  " << particleDescriptions[i1].unknownFloat1 << endl;
		out << "    Unknown Float 2:  " << particleDescriptions[i1].unknownFloat2 << endl;
		out << "    Unknown Float 3:  " << particleDescriptions[i1].unknownFloat3 << endl;
		out << "    Unknown Int 1:  " << particleDescriptions[i1].unknownInt1 << endl;
	};
	out << "  Has Unknown Floats 3:  " << hasUnknownFloats3 << endl;
	if ( (hasUnknownFloats3 != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < unknownFloats3.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Floats 3[" << i2 << "]:  " << unknownFloats3[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Unknown Short 1:  " << unknownShort1 << endl;
	out << "  Unknown Short 2:  " << unknownShort2 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiRotatingParticlesData::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSysData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiRotatingParticlesData::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
