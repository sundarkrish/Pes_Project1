/**
 * @file asciiclassifier.h
 * @brief Contains macro definitions and function prototypes for ascii character classification
 * @author Sundar Krishnakumar
 */
 
#ifndef __ASCII_CLASSIFIER_H__
#define __ASCII_CLASSIFIER_H__

typedef unsigned char uint8_t;
typedef char int8_t;

// Classification codes
#define UPPER_CASE 1
#define LOWER_CASE 2
#define DIGIT 3
#define WHITESPACE 4
#define SPECIAL_CHARACTER 5

uint8_t is_ascii(const uint8_t *);
uint8_t classifier(const uint8_t *);

#endif /*__ASCII_CLASSIFIER_H__*/