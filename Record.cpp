//
// Created by Lix Xeil on 09.05.2022.
//

#define _CRT_SECURE_NO_WARNINGS
#include "Record.h"
#include <string>
#include <vector>
#include <iostream>
using std::vector;
using std::string;


//  RECORD
//  constructor of the "Record" object
Record::Record(string i, unsigned int dur, string artName, string recName, unsigned int yr, float p)
{
    this->id = i;
    this->duration = dur;
    this->artistName = artName;
    this->recordName = recName;
    this->year = yr;
    this->price = p;
}


//  getters for id, duration, artistName, recordName, year and price
string Record::getId() const
{
    return this->id;
}

unsigned int Record::getDuration() const
{
    return this->duration;
}

string Record::getArtistName() const
{
    return this->artistName;
}

string Record::getRecordName() const
{
    return this->recordName;
}

unsigned int Record::getYear() const
{
    return this->year;
}

float Record::getPrice() const
{
    return this->price;
}


//  setters for id, duration, artistName, recordName, year and price
void Record::setId(string st)
{
    this->id = st;
}

void Record::setDuration(int dur)
{
    this->duration = dur;
}

void Record::setArtistName(string st)
{
    this->artistName = st;
}

void Record::setRecordName(string st)
{
    this->recordName = st;
}

void Record::setYear(int yr)
{
    this->year = yr;
}

void Record::setPrice(float p)
{
    this->price = p;
}


//  string representation of a "Record" object
string Record::toString()
{
    string strRepr;
    strRepr += id + ", " + std::to_string(duration) + ", " + artistName + ", " + recordName + ", " + std::to_string(year) + + ", " +
            std::to_string(price) + ", ";
    return strRepr;
}


//  getter of the support platform of the "Cassette" object
vector<Support> Record::getSupportType()
{
    vector<Support> st;
    st.push_back(Support::AUDIO_PLAYER);
    return st;
}



//  CASSETTE
//  constructor of the "Cassette" object
Cassette::Cassette(string i, unsigned int dur, string artName, string recName, unsigned int year, float p, bool isConvertable) : Record{ i, dur, artName, recName, year, p}
{
    this->isConvertable = isConvertable;
}


//  getter of the support platform of the "Cassette" object
vector<Support> Cassette::getSupportType()
{
    vector<Support> st;
    st.push_back(Support::AUDIO_PLAYER);
    if(isConvertable)
    {
        st.push_back(Support::COMPUTER);
        st.push_back(Support::PHYSICAL_MEMORY);
    }
    return st;
}


// string representation of a "Cassette" object
string Cassette::toString()
{
    string strRepr;
    strRepr += Record::toString();
    strRepr += isConvertable ? "true" : "false";
    strRepr += ", ";
    return strRepr;
}



//  CD
//  constructor of the "CD" object
CD::CD(string i, unsigned int dur, string artName, string recName, unsigned int yr, float p, bool isDownloadable, bool isConvertable) : Record{ i, dur, artName, recName, year, p}
{
    this->isDownloadable = isDownloadable;
    this->isConvertable = isConvertable;
}


//  getter of the support platform of the "CD" object
vector<Support> CD::getSupportType()
{
    vector<Support> st;
    st.push_back(Support::AUDIO_PLAYER);
    if(isConvertable)
    {
        st.push_back(Support::COMPUTER);
        st.push_back(Support::PHYSICAL_MEMORY);
    }
    if(isDownloadable)
    {
        //since it's already convertable, it's by default supported by computer
        st.push_back(Support::PHONE);
    }
    return st;
}


//  string representation of the "CD" object
string CD::toString()
{
    string strRepr;
    strRepr += Record::toString();
    strRepr += isDownloadable ? "true" : "false";
    strRepr += ", ";
    strRepr += isConvertable ? "true" : "false";
    strRepr += ", ";
    return strRepr;
}



//  VINYL
//  constructor of the "Vinyl" object
Vinyl::Vinyl(string i, unsigned int dur, string artName, string recName, unsigned int yr, float p, bool isDownloadable, bool isConvertable, bool isLimitedEdition) : Record{ i, dur, artName, recName, year, p}
{
    this->isDownloadable = isDownloadable;
    this->isConvertable = isConvertable;
    this->isLimitedEdition = isLimitedEdition;
}


//  getter of the support platform of the "Vinyl" object
vector <Support> Vinyl::getSupportType()
{
    vector<Support> st;
    st.push_back(Support::PICKUP);
    if(isConvertable)
    {
        st.push_back(Support::COMPUTER);
        st.push_back(Support::PHYSICAL_MEMORY);
    }
    if(isDownloadable)
    {
        //since it's already convertable, it's by default supported by computer
        st.push_back(Support::PHONE);
    }
    if(isLimitedEdition) st.push_back(Support::ARTISTIC_PURPOSES);
    return st;
}


//  string representation of the "Vinyl" object
string Vinyl::toString()
{
    string strRepr;
    strRepr += Record::toString();
    strRepr += isDownloadable ? "true" : "false";
    strRepr += ", ";
    strRepr += isConvertable ? "true" : "false";
    strRepr += ", ";
    strRepr += isLimitedEdition ? "true" : "false";
    strRepr += ", ";
    return strRepr;
}
