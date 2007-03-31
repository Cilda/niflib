/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiDefaultAVObjectPalette.h"
#include "../../include/gen/AVObject.h"
#include "../../include/obj/NiAVObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiDefaultAVObjectPalette::TYPE("NiDefaultAVObjectPalette", &NI_DEFAULT_A_V_OBJECT_PALETTE_PARENT::TypeConst() );

NiDefaultAVObjectPalette::NiDefaultAVObjectPalette() NI_DEFAULT_A_V_OBJECT_PALETTE_CONSTRUCT {}

NiDefaultAVObjectPalette::~NiDefaultAVObjectPalette() {}

void NiDefaultAVObjectPalette::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiDefaultAVObjectPalette::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiDefaultAVObjectPalette::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiDefaultAVObjectPalette::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiDefaultAVObjectPalette::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiDefaultAVObjectPalette::GetType() const {
	return TYPE;
};

vector<Ref<NiAVObject> > NiDefaultAVObjectPalette::GetObjs() const {
   vector<NiAVObjectRef> objRefs;
   for (vector<AVObject>::const_iterator itr = objs.begin(); itr != objs.end(); ++itr) {
      objRefs.push_back(itr->avObject);
   }
	return objRefs;
}

void NiDefaultAVObjectPalette::SetObjs( const vector<Ref<NiAVObject> >& value ) {
   objs.clear();
   for (vector<NiAVObjectRef>::const_iterator itr = value.begin(); itr != value.end(); ++itr) {
      AVObject obj;
      obj.name = (*itr)->GetName();
      obj.avObject = (*itr);
      objs.push_back(obj);
   }
}

const Type & NiDefaultAVObjectPalette::TypeConst() {
	return TYPE;
}
