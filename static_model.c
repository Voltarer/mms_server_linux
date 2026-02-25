/*
 * static_model.c
 *
 * automatically generated from src/model.icd
 */
#include "static_model.h"

static void initializeValues();

extern DataSet iedModelds_LD0_LLN0_battery;


extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda0;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda1;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda2;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda3;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda4;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda5;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda6;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda7;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda8;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda9;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda10;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda11;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda12;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda13;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda14;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda15;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda16;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda17;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda18;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda19;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda20;
extern DataSetEntry iedModelds_LD0_LLN0_battery_fcda21;

DataSetEntry iedModelds_LD0_LLN0_battery_fcda0 = {
  "LD0",
  false,
  "LPHD1$ST$PhyHealth$stVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda1
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda1 = {
  "LD0",
  false,
  "GGIO1$MX$AnIn1$mag$f", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda2
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda2 = {
  "LD0",
  false,
  "LPCP1$ST$PhyHealth$stVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda3
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda3 = {
  "LD0",
  false,
  "LPCP1$ST$RxCnt$actVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda4
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda4 = {
  "LD0",
  false,
  "LPCP1$ST$TxCnt$actVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda5
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda5 = {
  "LD0",
  false,
  "LCCH1$ST$ChLiv$stVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda6
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda6 = {
  "LD0",
  false,
  "LPCP2$ST$PhyHealth$stVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda7
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda7 = {
  "LD0",
  false,
  "LPCP2$ST$RxCnt$actVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda8
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda8 = {
  "LD0",
  false,
  "LPCP2$ST$TxCnt$actVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda9
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda9 = {
  "LD0",
  false,
  "LCCH2$ST$ChLiv$stVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda10
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda10 = {
  "LD0",
  false,
  "LPCP3$ST$PhyHealth$stVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda11
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda11 = {
  "LD0",
  false,
  "LPCP3$ST$RxCnt$actVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda12
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda12 = {
  "LD0",
  false,
  "LPCP3$ST$TxCnt$actVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda13
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda13 = {
  "LD0",
  false,
  "LPCP4$ST$PhyHealth$stVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda14
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda14 = {
  "LD0",
  false,
  "LPCP4$ST$RxCnt$actVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda15
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda15 = {
  "LD0",
  false,
  "LPCP4$ST$TxCnt$actVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda16
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda16 = {
  "LD0",
  false,
  "LPCP5$ST$PhyHealth$stVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda17
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda17 = {
  "LD0",
  false,
  "LPCP5$ST$RxCnt$actVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda18
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda18 = {
  "LD0",
  false,
  "LPCP5$ST$TxCnt$actVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda19
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda19 = {
  "LD0",
  false,
  "LPCP6$ST$PhyHealth$stVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda20
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda20 = {
  "LD0",
  false,
  "LPCP6$ST$RxCnt$actVal", 
  -1,
  NULL,
  NULL,
  &iedModelds_LD0_LLN0_battery_fcda21
};

DataSetEntry iedModelds_LD0_LLN0_battery_fcda21 = {
  "LD0",
  false,
  "LPCP6$ST$TxCnt$actVal", 
  -1,
  NULL,
  NULL,
  NULL
};

DataSet iedModelds_LD0_LLN0_battery = {
  "LD0",
  "LLN0$battery",
  22,
  &iedModelds_LD0_LLN0_battery_fcda0,
  NULL
};

LogicalDevice iedModel_LD0 = {
    LogicalDeviceModelType,
    "LD0",
    (ModelNode*) &iedModel,
    NULL,
    (ModelNode*) &iedModel_LD0_LLN0,
    NULL
};

LogicalNode iedModel_LD0_LLN0 = {
    LogicalNodeModelType,
    "LLN0",
    (ModelNode*) &iedModel_LD0,
    (ModelNode*) &iedModel_LD0_LPHD1,
    (ModelNode*) &iedModel_LD0_LLN0_Mod,
};

DataObject iedModel_LD0_LLN0_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LD0_LLN0,
    (ModelNode*) &iedModel_LD0_LLN0_Beh,
    (ModelNode*) &iedModel_LD0_LLN0_Mod_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LLN0_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LLN0_Mod,
    (ModelNode*) &iedModel_LD0_LLN0_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LLN0_Mod,
    (ModelNode*) &iedModel_LD0_LLN0_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LLN0_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LLN0_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LD0_LLN0,
    NULL,
    (ModelNode*) &iedModel_LD0_LLN0_Beh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LLN0_Beh,
    (ModelNode*) &iedModel_LD0_LLN0_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LLN0_Beh,
    (ModelNode*) &iedModel_LD0_LLN0_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LLN0_Beh,
    (ModelNode*) &iedModel_LD0_LLN0_Beh_vendor,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LLN0_Beh_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LD0_LLN0_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_LD0_LPHD1 = {
    LogicalNodeModelType,
    "LPHD1",
    (ModelNode*) &iedModel_LD0,
    (ModelNode*) &iedModel_LD0_GGIO1,
    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,
};

DataObject iedModel_LD0_LPHD1_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &iedModel_LD0_LPHD1,
    NULL,
    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPHD1_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPHD1_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPHD1_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth_vendor,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPHD1_PhyHealth_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LD0_LPHD1_PhyHealth,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_LD0_GGIO1 = {
    LogicalNodeModelType,
    "GGIO1",
    (ModelNode*) &iedModel_LD0,
    (ModelNode*) &iedModel_LD0_LCCH1,
    (ModelNode*) &iedModel_LD0_GGIO1_AnIn1,
};

DataObject iedModel_LD0_GGIO1_AnIn1 = {
    DataObjectModelType,
    "AnIn1",
    (ModelNode*) &iedModel_LD0_GGIO1,
    NULL,
    (ModelNode*) &iedModel_LD0_GGIO1_AnIn1_mag,
    0,
    -1
};

DataAttribute iedModel_LD0_GGIO1_AnIn1_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_LD0_GGIO1_AnIn1,
    (ModelNode*) &iedModel_LD0_GGIO1_AnIn1_q,
    (ModelNode*) &iedModel_LD0_GGIO1_AnIn1_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_GGIO1_AnIn1_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LD0_GGIO1_AnIn1_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_GGIO1_AnIn1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_GGIO1_AnIn1,
    (ModelNode*) &iedModel_LD0_GGIO1_AnIn1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_GGIO1_AnIn1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_GGIO1_AnIn1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

LogicalNode iedModel_LD0_LCCH1 = {
    LogicalNodeModelType,
    "LCCH1",
    (ModelNode*) &iedModel_LD0,
    (ModelNode*) &iedModel_LD0_LCCH2,
    (ModelNode*) &iedModel_LD0_LCCH1_Mod,
};

DataObject iedModel_LD0_LCCH1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LD0_LCCH1,
    (ModelNode*) &iedModel_LD0_LCCH1_Beh,
    (ModelNode*) &iedModel_LD0_LCCH1_Mod_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH1_Mod,
    (ModelNode*) &iedModel_LD0_LCCH1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH1_Mod,
    (ModelNode*) &iedModel_LD0_LCCH1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH1_Mod,
    (ModelNode*) &iedModel_LD0_LCCH1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_LD0_LCCH1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LD0_LCCH1,
    (ModelNode*) &iedModel_LD0_LCCH1_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH1_Beh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH1_Beh,
    (ModelNode*) &iedModel_LD0_LCCH1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH1_Beh,
    (ModelNode*) &iedModel_LD0_LCCH1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH1_ChLiv = {
    DataObjectModelType,
    "ChLiv",
    (ModelNode*) &iedModel_LD0_LCCH1,
    (ModelNode*) &iedModel_LD0_LCCH1_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH1_ChLiv_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH1_ChLiv_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH1_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH1_ChLiv_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_ChLiv_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH1_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH1_ChLiv_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_ChLiv_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH1_ChLiv,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH1_RedChLiv = {
    DataObjectModelType,
    "RedChLiv",
    (ModelNode*) &iedModel_LD0_LCCH1,
    (ModelNode*) &iedModel_LD0_LCCH1_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH1_RedChLiv_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH1_RedChLiv_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH1_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH1_RedChLiv_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_RedChLiv_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH1_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH1_RedChLiv_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_RedChLiv_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH1_RedChLiv,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH1_FerCh = {
    DataObjectModelType,
    "FerCh",
    (ModelNode*) &iedModel_LD0_LCCH1,
    (ModelNode*) &iedModel_LD0_LCCH1_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH1_FerCh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH1_FerCh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH1_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH1_FerCh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_FerCh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH1_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH1_FerCh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_FerCh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH1_FerCh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH1_RedFerCh = {
    DataObjectModelType,
    "RedFerCh",
    (ModelNode*) &iedModel_LD0_LCCH1,
    (ModelNode*) &iedModel_LD0_LCCH1_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH1_RedFerCh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH1_RedFerCh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH1_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH1_RedFerCh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_RedFerCh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH1_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH1_RedFerCh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_RedFerCh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH1_RedFerCh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH1_RxCnt = {
    DataObjectModelType,
    "RxCnt",
    (ModelNode*) &iedModel_LD0_LCCH1,
    (ModelNode*) &iedModel_LD0_LCCH1_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH1_RxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH1_RxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH1_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH1_RxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_RxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH1_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH1_RxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_RxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH1_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH1_RxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_RxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH1_RxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH1_RedRxCnt = {
    DataObjectModelType,
    "RedRxCnt",
    (ModelNode*) &iedModel_LD0_LCCH1,
    (ModelNode*) &iedModel_LD0_LCCH1_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH1_RedRxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH1_RedRxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH1_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH1_RedRxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_RedRxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH1_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH1_RedRxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_RedRxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH1_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH1_RedRxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_RedRxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH1_RedRxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH1_TxCnt = {
    DataObjectModelType,
    "TxCnt",
    (ModelNode*) &iedModel_LD0_LCCH1,
    (ModelNode*) &iedModel_LD0_LCCH1_RedCfg,
    (ModelNode*) &iedModel_LD0_LCCH1_TxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH1_TxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH1_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH1_TxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_TxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH1_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH1_TxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_TxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH1_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH1_TxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH1_TxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH1_TxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH1_RedCfg = {
    DataObjectModelType,
    "RedCfg",
    (ModelNode*) &iedModel_LD0_LCCH1,
    (ModelNode*) &iedModel_LD0_LCCH1_RedPathId,
    (ModelNode*) &iedModel_LD0_LCCH1_RedCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH1_RedCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LCCH1_RedCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH1_RedPathId = {
    DataObjectModelType,
    "RedPathId",
    (ModelNode*) &iedModel_LD0_LCCH1,
    (ModelNode*) &iedModel_LD0_LCCH1_PortRef,
    (ModelNode*) &iedModel_LD0_LCCH1_RedPathId_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH1_RedPathId_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LCCH1_RedPathId,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH1_PortRef = {
    DataObjectModelType,
    "PortRef",
    (ModelNode*) &iedModel_LD0_LCCH1,
    (ModelNode*) &iedModel_LD0_LCCH1_RedPortRef,
    (ModelNode*) &iedModel_LD0_LCCH1_PortRef_setSrcRef,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH1_PortRef_setSrcRef = {
    DataAttributeModelType,
    "setSrcRef",
    (ModelNode*) &iedModel_LD0_LCCH1_PortRef,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_129,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH1_RedPortRef = {
    DataObjectModelType,
    "RedPortRef",
    (ModelNode*) &iedModel_LD0_LCCH1,
    NULL,
    (ModelNode*) &iedModel_LD0_LCCH1_RedPortRef_setSrcRef,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH1_RedPortRef_setSrcRef = {
    DataAttributeModelType,
    "setSrcRef",
    (ModelNode*) &iedModel_LD0_LCCH1_RedPortRef,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_129,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

LogicalNode iedModel_LD0_LCCH2 = {
    LogicalNodeModelType,
    "LCCH2",
    (ModelNode*) &iedModel_LD0,
    (ModelNode*) &iedModel_LD0_LCCH3,
    (ModelNode*) &iedModel_LD0_LCCH2_Mod,
};

DataObject iedModel_LD0_LCCH2_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LD0_LCCH2,
    (ModelNode*) &iedModel_LD0_LCCH2_Beh,
    (ModelNode*) &iedModel_LD0_LCCH2_Mod_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH2_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH2_Mod,
    (ModelNode*) &iedModel_LD0_LCCH2_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH2_Mod,
    (ModelNode*) &iedModel_LD0_LCCH2_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH2_Mod,
    (ModelNode*) &iedModel_LD0_LCCH2_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_LD0_LCCH2_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH2_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LD0_LCCH2,
    (ModelNode*) &iedModel_LD0_LCCH2_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH2_Beh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH2_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH2_Beh,
    (ModelNode*) &iedModel_LD0_LCCH2_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH2_Beh,
    (ModelNode*) &iedModel_LD0_LCCH2_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH2_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH2_ChLiv = {
    DataObjectModelType,
    "ChLiv",
    (ModelNode*) &iedModel_LD0_LCCH2,
    (ModelNode*) &iedModel_LD0_LCCH2_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH2_ChLiv_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH2_ChLiv_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH2_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH2_ChLiv_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_ChLiv_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH2_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH2_ChLiv_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_ChLiv_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH2_ChLiv,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH2_RedChLiv = {
    DataObjectModelType,
    "RedChLiv",
    (ModelNode*) &iedModel_LD0_LCCH2,
    (ModelNode*) &iedModel_LD0_LCCH2_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH2_RedChLiv_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH2_RedChLiv_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH2_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH2_RedChLiv_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_RedChLiv_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH2_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH2_RedChLiv_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_RedChLiv_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH2_RedChLiv,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH2_FerCh = {
    DataObjectModelType,
    "FerCh",
    (ModelNode*) &iedModel_LD0_LCCH2,
    (ModelNode*) &iedModel_LD0_LCCH2_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH2_FerCh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH2_FerCh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH2_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH2_FerCh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_FerCh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH2_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH2_FerCh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_FerCh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH2_FerCh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH2_RedFerCh = {
    DataObjectModelType,
    "RedFerCh",
    (ModelNode*) &iedModel_LD0_LCCH2,
    (ModelNode*) &iedModel_LD0_LCCH2_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH2_RedFerCh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH2_RedFerCh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH2_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH2_RedFerCh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_RedFerCh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH2_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH2_RedFerCh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_RedFerCh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH2_RedFerCh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH2_RxCnt = {
    DataObjectModelType,
    "RxCnt",
    (ModelNode*) &iedModel_LD0_LCCH2,
    (ModelNode*) &iedModel_LD0_LCCH2_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH2_RxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH2_RxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH2_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH2_RxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_RxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH2_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH2_RxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_RxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH2_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH2_RxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_RxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH2_RxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH2_RedRxCnt = {
    DataObjectModelType,
    "RedRxCnt",
    (ModelNode*) &iedModel_LD0_LCCH2,
    (ModelNode*) &iedModel_LD0_LCCH2_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH2_RedRxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH2_RedRxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH2_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH2_RedRxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_RedRxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH2_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH2_RedRxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_RedRxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH2_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH2_RedRxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_RedRxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH2_RedRxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH2_TxCnt = {
    DataObjectModelType,
    "TxCnt",
    (ModelNode*) &iedModel_LD0_LCCH2,
    (ModelNode*) &iedModel_LD0_LCCH2_RedCfg,
    (ModelNode*) &iedModel_LD0_LCCH2_TxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH2_TxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH2_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH2_TxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_TxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH2_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH2_TxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_TxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH2_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH2_TxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH2_TxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH2_TxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH2_RedCfg = {
    DataObjectModelType,
    "RedCfg",
    (ModelNode*) &iedModel_LD0_LCCH2,
    (ModelNode*) &iedModel_LD0_LCCH2_RedPathId,
    (ModelNode*) &iedModel_LD0_LCCH2_RedCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH2_RedCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LCCH2_RedCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH2_RedPathId = {
    DataObjectModelType,
    "RedPathId",
    (ModelNode*) &iedModel_LD0_LCCH2,
    (ModelNode*) &iedModel_LD0_LCCH2_PortRef,
    (ModelNode*) &iedModel_LD0_LCCH2_RedPathId_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH2_RedPathId_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LCCH2_RedPathId,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH2_PortRef = {
    DataObjectModelType,
    "PortRef",
    (ModelNode*) &iedModel_LD0_LCCH2,
    (ModelNode*) &iedModel_LD0_LCCH2_RedPortRef,
    (ModelNode*) &iedModel_LD0_LCCH2_PortRef_setSrcRef,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH2_PortRef_setSrcRef = {
    DataAttributeModelType,
    "setSrcRef",
    (ModelNode*) &iedModel_LD0_LCCH2_PortRef,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_129,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH2_RedPortRef = {
    DataObjectModelType,
    "RedPortRef",
    (ModelNode*) &iedModel_LD0_LCCH2,
    NULL,
    (ModelNode*) &iedModel_LD0_LCCH2_RedPortRef_setSrcRef,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH2_RedPortRef_setSrcRef = {
    DataAttributeModelType,
    "setSrcRef",
    (ModelNode*) &iedModel_LD0_LCCH2_RedPortRef,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_129,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

LogicalNode iedModel_LD0_LCCH3 = {
    LogicalNodeModelType,
    "LCCH3",
    (ModelNode*) &iedModel_LD0,
    (ModelNode*) &iedModel_LD0_LCCH4,
    (ModelNode*) &iedModel_LD0_LCCH3_Mod,
};

DataObject iedModel_LD0_LCCH3_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LD0_LCCH3,
    (ModelNode*) &iedModel_LD0_LCCH3_Beh,
    (ModelNode*) &iedModel_LD0_LCCH3_Mod_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH3_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH3_Mod,
    (ModelNode*) &iedModel_LD0_LCCH3_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH3_Mod,
    (ModelNode*) &iedModel_LD0_LCCH3_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH3_Mod,
    (ModelNode*) &iedModel_LD0_LCCH3_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_LD0_LCCH3_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH3_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LD0_LCCH3,
    (ModelNode*) &iedModel_LD0_LCCH3_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH3_Beh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH3_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH3_Beh,
    (ModelNode*) &iedModel_LD0_LCCH3_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH3_Beh,
    (ModelNode*) &iedModel_LD0_LCCH3_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH3_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH3_ChLiv = {
    DataObjectModelType,
    "ChLiv",
    (ModelNode*) &iedModel_LD0_LCCH3,
    (ModelNode*) &iedModel_LD0_LCCH3_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH3_ChLiv_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH3_ChLiv_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH3_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH3_ChLiv_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_ChLiv_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH3_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH3_ChLiv_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_ChLiv_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH3_ChLiv,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH3_RedChLiv = {
    DataObjectModelType,
    "RedChLiv",
    (ModelNode*) &iedModel_LD0_LCCH3,
    (ModelNode*) &iedModel_LD0_LCCH3_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH3_RedChLiv_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH3_RedChLiv_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH3_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH3_RedChLiv_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_RedChLiv_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH3_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH3_RedChLiv_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_RedChLiv_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH3_RedChLiv,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH3_FerCh = {
    DataObjectModelType,
    "FerCh",
    (ModelNode*) &iedModel_LD0_LCCH3,
    (ModelNode*) &iedModel_LD0_LCCH3_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH3_FerCh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH3_FerCh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH3_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH3_FerCh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_FerCh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH3_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH3_FerCh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_FerCh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH3_FerCh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH3_RedFerCh = {
    DataObjectModelType,
    "RedFerCh",
    (ModelNode*) &iedModel_LD0_LCCH3,
    (ModelNode*) &iedModel_LD0_LCCH3_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH3_RedFerCh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH3_RedFerCh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH3_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH3_RedFerCh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_RedFerCh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH3_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH3_RedFerCh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_RedFerCh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH3_RedFerCh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH3_RxCnt = {
    DataObjectModelType,
    "RxCnt",
    (ModelNode*) &iedModel_LD0_LCCH3,
    (ModelNode*) &iedModel_LD0_LCCH3_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH3_RxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH3_RxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH3_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH3_RxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_RxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH3_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH3_RxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_RxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH3_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH3_RxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_RxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH3_RxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH3_RedRxCnt = {
    DataObjectModelType,
    "RedRxCnt",
    (ModelNode*) &iedModel_LD0_LCCH3,
    (ModelNode*) &iedModel_LD0_LCCH3_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH3_RedRxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH3_RedRxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH3_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH3_RedRxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_RedRxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH3_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH3_RedRxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_RedRxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH3_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH3_RedRxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_RedRxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH3_RedRxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH3_TxCnt = {
    DataObjectModelType,
    "TxCnt",
    (ModelNode*) &iedModel_LD0_LCCH3,
    (ModelNode*) &iedModel_LD0_LCCH3_RedCfg,
    (ModelNode*) &iedModel_LD0_LCCH3_TxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH3_TxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH3_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH3_TxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_TxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH3_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH3_TxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_TxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH3_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH3_TxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH3_TxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH3_TxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH3_RedCfg = {
    DataObjectModelType,
    "RedCfg",
    (ModelNode*) &iedModel_LD0_LCCH3,
    (ModelNode*) &iedModel_LD0_LCCH3_RedPathId,
    (ModelNode*) &iedModel_LD0_LCCH3_RedCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH3_RedCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LCCH3_RedCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH3_RedPathId = {
    DataObjectModelType,
    "RedPathId",
    (ModelNode*) &iedModel_LD0_LCCH3,
    (ModelNode*) &iedModel_LD0_LCCH3_PortRef,
    (ModelNode*) &iedModel_LD0_LCCH3_RedPathId_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH3_RedPathId_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LCCH3_RedPathId,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH3_PortRef = {
    DataObjectModelType,
    "PortRef",
    (ModelNode*) &iedModel_LD0_LCCH3,
    (ModelNode*) &iedModel_LD0_LCCH3_RedPortRef,
    (ModelNode*) &iedModel_LD0_LCCH3_PortRef_setSrcRef,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH3_PortRef_setSrcRef = {
    DataAttributeModelType,
    "setSrcRef",
    (ModelNode*) &iedModel_LD0_LCCH3_PortRef,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_129,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH3_RedPortRef = {
    DataObjectModelType,
    "RedPortRef",
    (ModelNode*) &iedModel_LD0_LCCH3,
    NULL,
    (ModelNode*) &iedModel_LD0_LCCH3_RedPortRef_setSrcRef,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH3_RedPortRef_setSrcRef = {
    DataAttributeModelType,
    "setSrcRef",
    (ModelNode*) &iedModel_LD0_LCCH3_RedPortRef,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_129,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

LogicalNode iedModel_LD0_LCCH4 = {
    LogicalNodeModelType,
    "LCCH4",
    (ModelNode*) &iedModel_LD0,
    (ModelNode*) &iedModel_LD0_LCCH5,
    (ModelNode*) &iedModel_LD0_LCCH4_Mod,
};

DataObject iedModel_LD0_LCCH4_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LD0_LCCH4,
    (ModelNode*) &iedModel_LD0_LCCH4_Beh,
    (ModelNode*) &iedModel_LD0_LCCH4_Mod_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH4_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH4_Mod,
    (ModelNode*) &iedModel_LD0_LCCH4_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH4_Mod,
    (ModelNode*) &iedModel_LD0_LCCH4_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH4_Mod,
    (ModelNode*) &iedModel_LD0_LCCH4_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_LD0_LCCH4_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH4_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LD0_LCCH4,
    (ModelNode*) &iedModel_LD0_LCCH4_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH4_Beh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH4_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH4_Beh,
    (ModelNode*) &iedModel_LD0_LCCH4_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH4_Beh,
    (ModelNode*) &iedModel_LD0_LCCH4_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH4_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH4_ChLiv = {
    DataObjectModelType,
    "ChLiv",
    (ModelNode*) &iedModel_LD0_LCCH4,
    (ModelNode*) &iedModel_LD0_LCCH4_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH4_ChLiv_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH4_ChLiv_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH4_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH4_ChLiv_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_ChLiv_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH4_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH4_ChLiv_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_ChLiv_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH4_ChLiv,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH4_RedChLiv = {
    DataObjectModelType,
    "RedChLiv",
    (ModelNode*) &iedModel_LD0_LCCH4,
    (ModelNode*) &iedModel_LD0_LCCH4_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH4_RedChLiv_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH4_RedChLiv_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH4_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH4_RedChLiv_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_RedChLiv_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH4_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH4_RedChLiv_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_RedChLiv_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH4_RedChLiv,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH4_FerCh = {
    DataObjectModelType,
    "FerCh",
    (ModelNode*) &iedModel_LD0_LCCH4,
    (ModelNode*) &iedModel_LD0_LCCH4_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH4_FerCh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH4_FerCh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH4_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH4_FerCh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_FerCh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH4_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH4_FerCh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_FerCh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH4_FerCh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH4_RedFerCh = {
    DataObjectModelType,
    "RedFerCh",
    (ModelNode*) &iedModel_LD0_LCCH4,
    (ModelNode*) &iedModel_LD0_LCCH4_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH4_RedFerCh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH4_RedFerCh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH4_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH4_RedFerCh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_RedFerCh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH4_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH4_RedFerCh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_RedFerCh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH4_RedFerCh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH4_RxCnt = {
    DataObjectModelType,
    "RxCnt",
    (ModelNode*) &iedModel_LD0_LCCH4,
    (ModelNode*) &iedModel_LD0_LCCH4_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH4_RxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH4_RxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH4_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH4_RxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_RxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH4_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH4_RxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_RxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH4_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH4_RxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_RxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH4_RxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH4_RedRxCnt = {
    DataObjectModelType,
    "RedRxCnt",
    (ModelNode*) &iedModel_LD0_LCCH4,
    (ModelNode*) &iedModel_LD0_LCCH4_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH4_RedRxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH4_RedRxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH4_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH4_RedRxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_RedRxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH4_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH4_RedRxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_RedRxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH4_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH4_RedRxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_RedRxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH4_RedRxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH4_TxCnt = {
    DataObjectModelType,
    "TxCnt",
    (ModelNode*) &iedModel_LD0_LCCH4,
    (ModelNode*) &iedModel_LD0_LCCH4_RedCfg,
    (ModelNode*) &iedModel_LD0_LCCH4_TxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH4_TxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH4_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH4_TxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_TxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH4_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH4_TxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_TxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH4_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH4_TxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH4_TxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH4_TxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH4_RedCfg = {
    DataObjectModelType,
    "RedCfg",
    (ModelNode*) &iedModel_LD0_LCCH4,
    (ModelNode*) &iedModel_LD0_LCCH4_RedPathId,
    (ModelNode*) &iedModel_LD0_LCCH4_RedCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH4_RedCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LCCH4_RedCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH4_RedPathId = {
    DataObjectModelType,
    "RedPathId",
    (ModelNode*) &iedModel_LD0_LCCH4,
    (ModelNode*) &iedModel_LD0_LCCH4_PortRef,
    (ModelNode*) &iedModel_LD0_LCCH4_RedPathId_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH4_RedPathId_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LCCH4_RedPathId,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH4_PortRef = {
    DataObjectModelType,
    "PortRef",
    (ModelNode*) &iedModel_LD0_LCCH4,
    (ModelNode*) &iedModel_LD0_LCCH4_RedPortRef,
    (ModelNode*) &iedModel_LD0_LCCH4_PortRef_setSrcRef,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH4_PortRef_setSrcRef = {
    DataAttributeModelType,
    "setSrcRef",
    (ModelNode*) &iedModel_LD0_LCCH4_PortRef,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_129,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH4_RedPortRef = {
    DataObjectModelType,
    "RedPortRef",
    (ModelNode*) &iedModel_LD0_LCCH4,
    NULL,
    (ModelNode*) &iedModel_LD0_LCCH4_RedPortRef_setSrcRef,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH4_RedPortRef_setSrcRef = {
    DataAttributeModelType,
    "setSrcRef",
    (ModelNode*) &iedModel_LD0_LCCH4_RedPortRef,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_129,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

LogicalNode iedModel_LD0_LCCH5 = {
    LogicalNodeModelType,
    "LCCH5",
    (ModelNode*) &iedModel_LD0,
    (ModelNode*) &iedModel_LD0_LCCH6,
    (ModelNode*) &iedModel_LD0_LCCH5_Mod,
};

DataObject iedModel_LD0_LCCH5_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LD0_LCCH5,
    (ModelNode*) &iedModel_LD0_LCCH5_Beh,
    (ModelNode*) &iedModel_LD0_LCCH5_Mod_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH5_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH5_Mod,
    (ModelNode*) &iedModel_LD0_LCCH5_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH5_Mod,
    (ModelNode*) &iedModel_LD0_LCCH5_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH5_Mod,
    (ModelNode*) &iedModel_LD0_LCCH5_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_LD0_LCCH5_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH5_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LD0_LCCH5,
    (ModelNode*) &iedModel_LD0_LCCH5_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH5_Beh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH5_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH5_Beh,
    (ModelNode*) &iedModel_LD0_LCCH5_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH5_Beh,
    (ModelNode*) &iedModel_LD0_LCCH5_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH5_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH5_ChLiv = {
    DataObjectModelType,
    "ChLiv",
    (ModelNode*) &iedModel_LD0_LCCH5,
    (ModelNode*) &iedModel_LD0_LCCH5_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH5_ChLiv_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH5_ChLiv_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH5_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH5_ChLiv_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_ChLiv_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH5_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH5_ChLiv_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_ChLiv_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH5_ChLiv,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH5_RedChLiv = {
    DataObjectModelType,
    "RedChLiv",
    (ModelNode*) &iedModel_LD0_LCCH5,
    (ModelNode*) &iedModel_LD0_LCCH5_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH5_RedChLiv_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH5_RedChLiv_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH5_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH5_RedChLiv_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_RedChLiv_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH5_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH5_RedChLiv_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_RedChLiv_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH5_RedChLiv,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH5_FerCh = {
    DataObjectModelType,
    "FerCh",
    (ModelNode*) &iedModel_LD0_LCCH5,
    (ModelNode*) &iedModel_LD0_LCCH5_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH5_FerCh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH5_FerCh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH5_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH5_FerCh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_FerCh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH5_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH5_FerCh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_FerCh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH5_FerCh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH5_RedFerCh = {
    DataObjectModelType,
    "RedFerCh",
    (ModelNode*) &iedModel_LD0_LCCH5,
    (ModelNode*) &iedModel_LD0_LCCH5_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH5_RedFerCh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH5_RedFerCh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH5_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH5_RedFerCh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_RedFerCh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH5_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH5_RedFerCh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_RedFerCh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH5_RedFerCh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH5_RxCnt = {
    DataObjectModelType,
    "RxCnt",
    (ModelNode*) &iedModel_LD0_LCCH5,
    (ModelNode*) &iedModel_LD0_LCCH5_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH5_RxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH5_RxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH5_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH5_RxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_RxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH5_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH5_RxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_RxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH5_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH5_RxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_RxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH5_RxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH5_RedRxCnt = {
    DataObjectModelType,
    "RedRxCnt",
    (ModelNode*) &iedModel_LD0_LCCH5,
    (ModelNode*) &iedModel_LD0_LCCH5_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH5_RedRxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH5_RedRxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH5_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH5_RedRxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_RedRxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH5_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH5_RedRxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_RedRxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH5_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH5_RedRxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_RedRxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH5_RedRxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH5_TxCnt = {
    DataObjectModelType,
    "TxCnt",
    (ModelNode*) &iedModel_LD0_LCCH5,
    (ModelNode*) &iedModel_LD0_LCCH5_RedCfg,
    (ModelNode*) &iedModel_LD0_LCCH5_TxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH5_TxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH5_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH5_TxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_TxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH5_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH5_TxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_TxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH5_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH5_TxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH5_TxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH5_TxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH5_RedCfg = {
    DataObjectModelType,
    "RedCfg",
    (ModelNode*) &iedModel_LD0_LCCH5,
    (ModelNode*) &iedModel_LD0_LCCH5_RedPathId,
    (ModelNode*) &iedModel_LD0_LCCH5_RedCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH5_RedCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LCCH5_RedCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH5_RedPathId = {
    DataObjectModelType,
    "RedPathId",
    (ModelNode*) &iedModel_LD0_LCCH5,
    (ModelNode*) &iedModel_LD0_LCCH5_PortRef,
    (ModelNode*) &iedModel_LD0_LCCH5_RedPathId_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH5_RedPathId_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LCCH5_RedPathId,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH5_PortRef = {
    DataObjectModelType,
    "PortRef",
    (ModelNode*) &iedModel_LD0_LCCH5,
    (ModelNode*) &iedModel_LD0_LCCH5_RedPortRef,
    (ModelNode*) &iedModel_LD0_LCCH5_PortRef_setSrcRef,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH5_PortRef_setSrcRef = {
    DataAttributeModelType,
    "setSrcRef",
    (ModelNode*) &iedModel_LD0_LCCH5_PortRef,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_129,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH5_RedPortRef = {
    DataObjectModelType,
    "RedPortRef",
    (ModelNode*) &iedModel_LD0_LCCH5,
    NULL,
    (ModelNode*) &iedModel_LD0_LCCH5_RedPortRef_setSrcRef,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH5_RedPortRef_setSrcRef = {
    DataAttributeModelType,
    "setSrcRef",
    (ModelNode*) &iedModel_LD0_LCCH5_RedPortRef,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_129,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

LogicalNode iedModel_LD0_LCCH6 = {
    LogicalNodeModelType,
    "LCCH6",
    (ModelNode*) &iedModel_LD0,
    (ModelNode*) &iedModel_LD0_LCCH7,
    (ModelNode*) &iedModel_LD0_LCCH6_Mod,
};

DataObject iedModel_LD0_LCCH6_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LD0_LCCH6,
    (ModelNode*) &iedModel_LD0_LCCH6_Beh,
    (ModelNode*) &iedModel_LD0_LCCH6_Mod_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH6_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH6_Mod,
    (ModelNode*) &iedModel_LD0_LCCH6_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH6_Mod,
    (ModelNode*) &iedModel_LD0_LCCH6_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH6_Mod,
    (ModelNode*) &iedModel_LD0_LCCH6_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_LD0_LCCH6_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH6_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LD0_LCCH6,
    (ModelNode*) &iedModel_LD0_LCCH6_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH6_Beh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH6_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH6_Beh,
    (ModelNode*) &iedModel_LD0_LCCH6_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH6_Beh,
    (ModelNode*) &iedModel_LD0_LCCH6_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH6_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH6_ChLiv = {
    DataObjectModelType,
    "ChLiv",
    (ModelNode*) &iedModel_LD0_LCCH6,
    (ModelNode*) &iedModel_LD0_LCCH6_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH6_ChLiv_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH6_ChLiv_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH6_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH6_ChLiv_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_ChLiv_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH6_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH6_ChLiv_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_ChLiv_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH6_ChLiv,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH6_RedChLiv = {
    DataObjectModelType,
    "RedChLiv",
    (ModelNode*) &iedModel_LD0_LCCH6,
    (ModelNode*) &iedModel_LD0_LCCH6_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH6_RedChLiv_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH6_RedChLiv_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH6_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH6_RedChLiv_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_RedChLiv_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH6_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH6_RedChLiv_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_RedChLiv_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH6_RedChLiv,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH6_FerCh = {
    DataObjectModelType,
    "FerCh",
    (ModelNode*) &iedModel_LD0_LCCH6,
    (ModelNode*) &iedModel_LD0_LCCH6_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH6_FerCh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH6_FerCh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH6_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH6_FerCh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_FerCh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH6_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH6_FerCh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_FerCh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH6_FerCh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH6_RedFerCh = {
    DataObjectModelType,
    "RedFerCh",
    (ModelNode*) &iedModel_LD0_LCCH6,
    (ModelNode*) &iedModel_LD0_LCCH6_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH6_RedFerCh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH6_RedFerCh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH6_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH6_RedFerCh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_RedFerCh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH6_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH6_RedFerCh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_RedFerCh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH6_RedFerCh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH6_RxCnt = {
    DataObjectModelType,
    "RxCnt",
    (ModelNode*) &iedModel_LD0_LCCH6,
    (ModelNode*) &iedModel_LD0_LCCH6_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH6_RxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH6_RxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH6_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH6_RxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_RxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH6_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH6_RxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_RxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH6_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH6_RxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_RxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH6_RxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH6_RedRxCnt = {
    DataObjectModelType,
    "RedRxCnt",
    (ModelNode*) &iedModel_LD0_LCCH6,
    (ModelNode*) &iedModel_LD0_LCCH6_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH6_RedRxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH6_RedRxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH6_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH6_RedRxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_RedRxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH6_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH6_RedRxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_RedRxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH6_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH6_RedRxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_RedRxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH6_RedRxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH6_TxCnt = {
    DataObjectModelType,
    "TxCnt",
    (ModelNode*) &iedModel_LD0_LCCH6,
    (ModelNode*) &iedModel_LD0_LCCH6_RedCfg,
    (ModelNode*) &iedModel_LD0_LCCH6_TxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH6_TxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH6_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH6_TxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_TxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH6_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH6_TxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_TxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH6_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH6_TxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH6_TxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH6_TxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH6_RedCfg = {
    DataObjectModelType,
    "RedCfg",
    (ModelNode*) &iedModel_LD0_LCCH6,
    (ModelNode*) &iedModel_LD0_LCCH6_RedPathId,
    (ModelNode*) &iedModel_LD0_LCCH6_RedCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH6_RedCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LCCH6_RedCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH6_RedPathId = {
    DataObjectModelType,
    "RedPathId",
    (ModelNode*) &iedModel_LD0_LCCH6,
    (ModelNode*) &iedModel_LD0_LCCH6_PortRef,
    (ModelNode*) &iedModel_LD0_LCCH6_RedPathId_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH6_RedPathId_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LCCH6_RedPathId,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH6_PortRef = {
    DataObjectModelType,
    "PortRef",
    (ModelNode*) &iedModel_LD0_LCCH6,
    (ModelNode*) &iedModel_LD0_LCCH6_RedPortRef,
    (ModelNode*) &iedModel_LD0_LCCH6_PortRef_setSrcRef,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH6_PortRef_setSrcRef = {
    DataAttributeModelType,
    "setSrcRef",
    (ModelNode*) &iedModel_LD0_LCCH6_PortRef,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_129,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH6_RedPortRef = {
    DataObjectModelType,
    "RedPortRef",
    (ModelNode*) &iedModel_LD0_LCCH6,
    NULL,
    (ModelNode*) &iedModel_LD0_LCCH6_RedPortRef_setSrcRef,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH6_RedPortRef_setSrcRef = {
    DataAttributeModelType,
    "setSrcRef",
    (ModelNode*) &iedModel_LD0_LCCH6_RedPortRef,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_129,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

LogicalNode iedModel_LD0_LCCH7 = {
    LogicalNodeModelType,
    "LCCH7",
    (ModelNode*) &iedModel_LD0,
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LCCH7_Mod,
};

DataObject iedModel_LD0_LCCH7_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LD0_LCCH7,
    (ModelNode*) &iedModel_LD0_LCCH7_Beh,
    (ModelNode*) &iedModel_LD0_LCCH7_Mod_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH7_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH7_Mod,
    (ModelNode*) &iedModel_LD0_LCCH7_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH7_Mod,
    (ModelNode*) &iedModel_LD0_LCCH7_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH7_Mod,
    (ModelNode*) &iedModel_LD0_LCCH7_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_LD0_LCCH7_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH7_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LD0_LCCH7,
    (ModelNode*) &iedModel_LD0_LCCH7_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH7_Beh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH7_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH7_Beh,
    (ModelNode*) &iedModel_LD0_LCCH7_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH7_Beh,
    (ModelNode*) &iedModel_LD0_LCCH7_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH7_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH7_ChLiv = {
    DataObjectModelType,
    "ChLiv",
    (ModelNode*) &iedModel_LD0_LCCH7,
    (ModelNode*) &iedModel_LD0_LCCH7_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH7_ChLiv_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH7_ChLiv_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH7_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH7_ChLiv_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_ChLiv_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH7_ChLiv,
    (ModelNode*) &iedModel_LD0_LCCH7_ChLiv_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_ChLiv_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH7_ChLiv,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH7_RedChLiv = {
    DataObjectModelType,
    "RedChLiv",
    (ModelNode*) &iedModel_LD0_LCCH7,
    (ModelNode*) &iedModel_LD0_LCCH7_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH7_RedChLiv_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH7_RedChLiv_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH7_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH7_RedChLiv_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_RedChLiv_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH7_RedChLiv,
    (ModelNode*) &iedModel_LD0_LCCH7_RedChLiv_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_RedChLiv_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH7_RedChLiv,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH7_FerCh = {
    DataObjectModelType,
    "FerCh",
    (ModelNode*) &iedModel_LD0_LCCH7,
    (ModelNode*) &iedModel_LD0_LCCH7_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH7_FerCh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH7_FerCh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH7_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH7_FerCh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_FerCh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH7_FerCh,
    (ModelNode*) &iedModel_LD0_LCCH7_FerCh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_FerCh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH7_FerCh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH7_RedFerCh = {
    DataObjectModelType,
    "RedFerCh",
    (ModelNode*) &iedModel_LD0_LCCH7,
    (ModelNode*) &iedModel_LD0_LCCH7_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH7_RedFerCh_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH7_RedFerCh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LCCH7_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH7_RedFerCh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_RedFerCh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH7_RedFerCh,
    (ModelNode*) &iedModel_LD0_LCCH7_RedFerCh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_RedFerCh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH7_RedFerCh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LCCH7_RxCnt = {
    DataObjectModelType,
    "RxCnt",
    (ModelNode*) &iedModel_LD0_LCCH7,
    (ModelNode*) &iedModel_LD0_LCCH7_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH7_RxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH7_RxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH7_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH7_RxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_RxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH7_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH7_RxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_RxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH7_RxCnt,
    (ModelNode*) &iedModel_LD0_LCCH7_RxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_RxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH7_RxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH7_RedRxCnt = {
    DataObjectModelType,
    "RedRxCnt",
    (ModelNode*) &iedModel_LD0_LCCH7,
    (ModelNode*) &iedModel_LD0_LCCH7_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH7_RedRxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH7_RedRxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH7_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH7_RedRxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_RedRxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH7_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH7_RedRxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_RedRxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH7_RedRxCnt,
    (ModelNode*) &iedModel_LD0_LCCH7_RedRxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_RedRxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH7_RedRxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH7_TxCnt = {
    DataObjectModelType,
    "TxCnt",
    (ModelNode*) &iedModel_LD0_LCCH7,
    (ModelNode*) &iedModel_LD0_LCCH7_RedCfg,
    (ModelNode*) &iedModel_LD0_LCCH7_TxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH7_TxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LCCH7_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH7_TxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_TxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LCCH7_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH7_TxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_TxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LCCH7_TxCnt,
    (ModelNode*) &iedModel_LD0_LCCH7_TxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LCCH7_TxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LCCH7_TxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH7_RedCfg = {
    DataObjectModelType,
    "RedCfg",
    (ModelNode*) &iedModel_LD0_LCCH7,
    (ModelNode*) &iedModel_LD0_LCCH7_RedPathId,
    (ModelNode*) &iedModel_LD0_LCCH7_RedCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH7_RedCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LCCH7_RedCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH7_RedPathId = {
    DataObjectModelType,
    "RedPathId",
    (ModelNode*) &iedModel_LD0_LCCH7,
    (ModelNode*) &iedModel_LD0_LCCH7_PortRef,
    (ModelNode*) &iedModel_LD0_LCCH7_RedPathId_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH7_RedPathId_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LCCH7_RedPathId,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH7_PortRef = {
    DataObjectModelType,
    "PortRef",
    (ModelNode*) &iedModel_LD0_LCCH7,
    (ModelNode*) &iedModel_LD0_LCCH7_RedPortRef,
    (ModelNode*) &iedModel_LD0_LCCH7_PortRef_setSrcRef,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH7_PortRef_setSrcRef = {
    DataAttributeModelType,
    "setSrcRef",
    (ModelNode*) &iedModel_LD0_LCCH7_PortRef,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_129,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LCCH7_RedPortRef = {
    DataObjectModelType,
    "RedPortRef",
    (ModelNode*) &iedModel_LD0_LCCH7,
    NULL,
    (ModelNode*) &iedModel_LD0_LCCH7_RedPortRef_setSrcRef,
    0,
    -1
};

DataAttribute iedModel_LD0_LCCH7_RedPortRef_setSrcRef = {
    DataAttributeModelType,
    "setSrcRef",
    (ModelNode*) &iedModel_LD0_LCCH7_RedPortRef,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_129,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

LogicalNode iedModel_LD0_LPCP1 = {
    LogicalNodeModelType,
    "LPCP1",
    (ModelNode*) &iedModel_LD0,
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP1_NamPlt,
};

DataObject iedModel_LD0_LPCP1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_PhyNam,
    (ModelNode*) &iedModel_LD0_LPCP1_NamPlt_vendor,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LD0_LPCP1_NamPlt,
    (ModelNode*) &iedModel_LD0_LPCP1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LD0_LPCP1_NamPlt,
    (ModelNode*) &iedModel_LD0_LPCP1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LD0_LPCP1_NamPlt,
    (ModelNode*) &iedModel_LD0_LPCP1_NamPlt_lnNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_NamPlt_lnNs = {
    DataAttributeModelType,
    "lnNs",
    (ModelNode*) &iedModel_LD0_LPCP1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPCP1_PhyNam_vendor,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LD0_LPCP1_PhyNam,
    (ModelNode*) &iedModel_LD0_LPCP1_PhyNam_model,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_PhyNam_model = {
    DataAttributeModelType,
    "model",
    (ModelNode*) &iedModel_LD0_LPCP1_PhyNam,
    (ModelNode*) &iedModel_LD0_LPCP1_PhyNam_location,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_PhyNam_location = {
    DataAttributeModelType,
    "location",
    (ModelNode*) &iedModel_LD0_LPCP1_PhyNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP1_PhyHealth_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP1_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPCP1_PhyHealth_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP1_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPCP1_PhyHealth_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP1_PhyHealth,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_RxCnt = {
    DataObjectModelType,
    "RxCnt",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP1_RxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_RxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LPCP1_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP1_RxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_RxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP1_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP1_RxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_RxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP1_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP1_RxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_RxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LPCP1_RxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_TxCnt = {
    DataObjectModelType,
    "TxCnt",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_FerPort,
    (ModelNode*) &iedModel_LD0_LPCP1_TxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_TxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LPCP1_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP1_TxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_TxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP1_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP1_TxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_TxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP1_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP1_TxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_TxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LPCP1_TxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_FerPort = {
    DataObjectModelType,
    "FerPort",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_Mau,
    (ModelNode*) &iedModel_LD0_LPCP1_FerPort_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_FerPort_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP1_FerPort,
    (ModelNode*) &iedModel_LD0_LPCP1_FerPort_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_FerPort_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP1_FerPort,
    (ModelNode*) &iedModel_LD0_LPCP1_FerPort_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_FerPort_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP1_FerPort,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_Mau = {
    DataObjectModelType,
    "Mau",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_AutoNgt,
    (ModelNode*) &iedModel_LD0_LPCP1_Mau_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_Mau_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP1_Mau,
    (ModelNode*) &iedModel_LD0_LPCP1_Mau_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_Mau_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP1_Mau,
    (ModelNode*) &iedModel_LD0_LPCP1_Mau_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_Mau_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP1_Mau,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_AutoNgt = {
    DataObjectModelType,
    "AutoNgt",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_PortNam,
    (ModelNode*) &iedModel_LD0_LPCP1_AutoNgt_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_AutoNgt_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP1_AutoNgt,
    (ModelNode*) &iedModel_LD0_LPCP1_AutoNgt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_AutoNgt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP1_AutoNgt,
    (ModelNode*) &iedModel_LD0_LPCP1_AutoNgt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP1_AutoNgt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP1_AutoNgt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_PortNam = {
    DataObjectModelType,
    "PortNam",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_PortNum,
    (ModelNode*) &iedModel_LD0_LPCP1_PortNam_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_PortNam_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP1_PortNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_255,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_PortNum = {
    DataObjectModelType,
    "PortNum",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_PortMac,
    (ModelNode*) &iedModel_LD0_LPCP1_PortNum_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_PortNum_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP1_PortNum,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_PortMac = {
    DataObjectModelType,
    "PortMac",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfg,
    (ModelNode*) &iedModel_LD0_LPCP1_PortMac_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_PortMac_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP1_PortMac,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_255,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_MauCfg = {
    DataObjectModelType,
    "MauCfg",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfgCap1,
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_MauCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_MauCfgCap1 = {
    DataObjectModelType,
    "MauCfgCap1",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfgCap2,
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfgCap1_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_MauCfgCap1_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfgCap1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_MauCfgCap2 = {
    DataObjectModelType,
    "MauCfgCap2",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfgCap3,
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfgCap2_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_MauCfgCap2_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfgCap2,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_MauCfgCap3 = {
    DataObjectModelType,
    "MauCfgCap3",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfgCap4,
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfgCap3_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_MauCfgCap3_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfgCap3,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_MauCfgCap4 = {
    DataObjectModelType,
    "MauCfgCap4",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfgCap5,
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfgCap4_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_MauCfgCap4_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfgCap4,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_MauCfgCap5 = {
    DataObjectModelType,
    "MauCfgCap5",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfgCap6,
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfgCap5_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_MauCfgCap5_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfgCap5,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_MauCfgCap6 = {
    DataObjectModelType,
    "MauCfgCap6",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_AutoNgtCfg,
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfgCap6_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_MauCfgCap6_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP1_MauCfgCap6,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_AutoNgtCfg = {
    DataObjectModelType,
    "AutoNgtCfg",
    (ModelNode*) &iedModel_LD0_LPCP1,
    (ModelNode*) &iedModel_LD0_LPCP1_AdminCfg,
    (ModelNode*) &iedModel_LD0_LPCP1_AutoNgtCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_AutoNgtCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP1_AutoNgtCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP1_AdminCfg = {
    DataObjectModelType,
    "AdminCfg",
    (ModelNode*) &iedModel_LD0_LPCP1,
    NULL,
    (ModelNode*) &iedModel_LD0_LPCP1_AdminCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP1_AdminCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP1_AdminCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

LogicalNode iedModel_LD0_LPCP2 = {
    LogicalNodeModelType,
    "LPCP2",
    (ModelNode*) &iedModel_LD0,
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP2_NamPlt,
};

DataObject iedModel_LD0_LPCP2_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_PhyNam,
    (ModelNode*) &iedModel_LD0_LPCP2_NamPlt_vendor,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LD0_LPCP2_NamPlt,
    (ModelNode*) &iedModel_LD0_LPCP2_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LD0_LPCP2_NamPlt,
    (ModelNode*) &iedModel_LD0_LPCP2_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LD0_LPCP2_NamPlt,
    (ModelNode*) &iedModel_LD0_LPCP2_NamPlt_lnNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_NamPlt_lnNs = {
    DataAttributeModelType,
    "lnNs",
    (ModelNode*) &iedModel_LD0_LPCP2_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPCP2_PhyNam_vendor,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LD0_LPCP2_PhyNam,
    (ModelNode*) &iedModel_LD0_LPCP2_PhyNam_model,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_PhyNam_model = {
    DataAttributeModelType,
    "model",
    (ModelNode*) &iedModel_LD0_LPCP2_PhyNam,
    (ModelNode*) &iedModel_LD0_LPCP2_PhyNam_location,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_PhyNam_location = {
    DataAttributeModelType,
    "location",
    (ModelNode*) &iedModel_LD0_LPCP2_PhyNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP2_PhyHealth_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP2_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPCP2_PhyHealth_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP2_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPCP2_PhyHealth_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP2_PhyHealth,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_RxCnt = {
    DataObjectModelType,
    "RxCnt",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP2_RxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_RxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LPCP2_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP2_RxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_RxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP2_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP2_RxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_RxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP2_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP2_RxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_RxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LPCP2_RxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_TxCnt = {
    DataObjectModelType,
    "TxCnt",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_FerPort,
    (ModelNode*) &iedModel_LD0_LPCP2_TxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_TxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LPCP2_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP2_TxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_TxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP2_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP2_TxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_TxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP2_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP2_TxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_TxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LPCP2_TxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_FerPort = {
    DataObjectModelType,
    "FerPort",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_Mau,
    (ModelNode*) &iedModel_LD0_LPCP2_FerPort_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_FerPort_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP2_FerPort,
    (ModelNode*) &iedModel_LD0_LPCP2_FerPort_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_FerPort_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP2_FerPort,
    (ModelNode*) &iedModel_LD0_LPCP2_FerPort_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_FerPort_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP2_FerPort,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_Mau = {
    DataObjectModelType,
    "Mau",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_AutoNgt,
    (ModelNode*) &iedModel_LD0_LPCP2_Mau_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_Mau_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP2_Mau,
    (ModelNode*) &iedModel_LD0_LPCP2_Mau_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_Mau_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP2_Mau,
    (ModelNode*) &iedModel_LD0_LPCP2_Mau_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_Mau_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP2_Mau,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_AutoNgt = {
    DataObjectModelType,
    "AutoNgt",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_PortNam,
    (ModelNode*) &iedModel_LD0_LPCP2_AutoNgt_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_AutoNgt_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP2_AutoNgt,
    (ModelNode*) &iedModel_LD0_LPCP2_AutoNgt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_AutoNgt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP2_AutoNgt,
    (ModelNode*) &iedModel_LD0_LPCP2_AutoNgt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP2_AutoNgt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP2_AutoNgt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_PortNam = {
    DataObjectModelType,
    "PortNam",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_PortNum,
    (ModelNode*) &iedModel_LD0_LPCP2_PortNam_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_PortNam_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP2_PortNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_255,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_PortNum = {
    DataObjectModelType,
    "PortNum",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_PortMac,
    (ModelNode*) &iedModel_LD0_LPCP2_PortNum_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_PortNum_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP2_PortNum,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_PortMac = {
    DataObjectModelType,
    "PortMac",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfg,
    (ModelNode*) &iedModel_LD0_LPCP2_PortMac_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_PortMac_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP2_PortMac,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_255,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_MauCfg = {
    DataObjectModelType,
    "MauCfg",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfgCap1,
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_MauCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_MauCfgCap1 = {
    DataObjectModelType,
    "MauCfgCap1",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfgCap2,
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfgCap1_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_MauCfgCap1_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfgCap1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_MauCfgCap2 = {
    DataObjectModelType,
    "MauCfgCap2",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfgCap3,
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfgCap2_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_MauCfgCap2_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfgCap2,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_MauCfgCap3 = {
    DataObjectModelType,
    "MauCfgCap3",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfgCap4,
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfgCap3_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_MauCfgCap3_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfgCap3,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_MauCfgCap4 = {
    DataObjectModelType,
    "MauCfgCap4",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfgCap5,
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfgCap4_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_MauCfgCap4_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfgCap4,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_MauCfgCap5 = {
    DataObjectModelType,
    "MauCfgCap5",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfgCap6,
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfgCap5_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_MauCfgCap5_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfgCap5,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_MauCfgCap6 = {
    DataObjectModelType,
    "MauCfgCap6",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_AutoNgtCfg,
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfgCap6_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_MauCfgCap6_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP2_MauCfgCap6,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_AutoNgtCfg = {
    DataObjectModelType,
    "AutoNgtCfg",
    (ModelNode*) &iedModel_LD0_LPCP2,
    (ModelNode*) &iedModel_LD0_LPCP2_AdminCfg,
    (ModelNode*) &iedModel_LD0_LPCP2_AutoNgtCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_AutoNgtCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP2_AutoNgtCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP2_AdminCfg = {
    DataObjectModelType,
    "AdminCfg",
    (ModelNode*) &iedModel_LD0_LPCP2,
    NULL,
    (ModelNode*) &iedModel_LD0_LPCP2_AdminCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP2_AdminCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP2_AdminCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

LogicalNode iedModel_LD0_LPCP3 = {
    LogicalNodeModelType,
    "LPCP3",
    (ModelNode*) &iedModel_LD0,
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP3_NamPlt,
};

DataObject iedModel_LD0_LPCP3_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_PhyNam,
    (ModelNode*) &iedModel_LD0_LPCP3_NamPlt_vendor,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LD0_LPCP3_NamPlt,
    (ModelNode*) &iedModel_LD0_LPCP3_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LD0_LPCP3_NamPlt,
    (ModelNode*) &iedModel_LD0_LPCP3_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LD0_LPCP3_NamPlt,
    (ModelNode*) &iedModel_LD0_LPCP3_NamPlt_lnNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_NamPlt_lnNs = {
    DataAttributeModelType,
    "lnNs",
    (ModelNode*) &iedModel_LD0_LPCP3_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPCP3_PhyNam_vendor,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LD0_LPCP3_PhyNam,
    (ModelNode*) &iedModel_LD0_LPCP3_PhyNam_model,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_PhyNam_model = {
    DataAttributeModelType,
    "model",
    (ModelNode*) &iedModel_LD0_LPCP3_PhyNam,
    (ModelNode*) &iedModel_LD0_LPCP3_PhyNam_location,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_PhyNam_location = {
    DataAttributeModelType,
    "location",
    (ModelNode*) &iedModel_LD0_LPCP3_PhyNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP3_PhyHealth_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP3_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPCP3_PhyHealth_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP3_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPCP3_PhyHealth_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP3_PhyHealth,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_RxCnt = {
    DataObjectModelType,
    "RxCnt",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP3_RxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_RxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LPCP3_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP3_RxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_RxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP3_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP3_RxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_RxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP3_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP3_RxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_RxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LPCP3_RxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_TxCnt = {
    DataObjectModelType,
    "TxCnt",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_FerPort,
    (ModelNode*) &iedModel_LD0_LPCP3_TxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_TxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LPCP3_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP3_TxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_TxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP3_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP3_TxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_TxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP3_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP3_TxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_TxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LPCP3_TxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_FerPort = {
    DataObjectModelType,
    "FerPort",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_Mau,
    (ModelNode*) &iedModel_LD0_LPCP3_FerPort_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_FerPort_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP3_FerPort,
    (ModelNode*) &iedModel_LD0_LPCP3_FerPort_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_FerPort_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP3_FerPort,
    (ModelNode*) &iedModel_LD0_LPCP3_FerPort_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_FerPort_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP3_FerPort,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_Mau = {
    DataObjectModelType,
    "Mau",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_AutoNgt,
    (ModelNode*) &iedModel_LD0_LPCP3_Mau_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_Mau_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP3_Mau,
    (ModelNode*) &iedModel_LD0_LPCP3_Mau_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_Mau_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP3_Mau,
    (ModelNode*) &iedModel_LD0_LPCP3_Mau_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_Mau_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP3_Mau,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_AutoNgt = {
    DataObjectModelType,
    "AutoNgt",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_PortNam,
    (ModelNode*) &iedModel_LD0_LPCP3_AutoNgt_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_AutoNgt_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP3_AutoNgt,
    (ModelNode*) &iedModel_LD0_LPCP3_AutoNgt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_AutoNgt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP3_AutoNgt,
    (ModelNode*) &iedModel_LD0_LPCP3_AutoNgt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP3_AutoNgt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP3_AutoNgt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_PortNam = {
    DataObjectModelType,
    "PortNam",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_PortNum,
    (ModelNode*) &iedModel_LD0_LPCP3_PortNam_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_PortNam_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP3_PortNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_255,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_PortNum = {
    DataObjectModelType,
    "PortNum",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_PortMac,
    (ModelNode*) &iedModel_LD0_LPCP3_PortNum_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_PortNum_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP3_PortNum,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_PortMac = {
    DataObjectModelType,
    "PortMac",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfg,
    (ModelNode*) &iedModel_LD0_LPCP3_PortMac_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_PortMac_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP3_PortMac,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_255,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_MauCfg = {
    DataObjectModelType,
    "MauCfg",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfgCap1,
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_MauCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_MauCfgCap1 = {
    DataObjectModelType,
    "MauCfgCap1",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfgCap2,
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfgCap1_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_MauCfgCap1_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfgCap1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_MauCfgCap2 = {
    DataObjectModelType,
    "MauCfgCap2",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfgCap3,
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfgCap2_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_MauCfgCap2_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfgCap2,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_MauCfgCap3 = {
    DataObjectModelType,
    "MauCfgCap3",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfgCap4,
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfgCap3_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_MauCfgCap3_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfgCap3,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_MauCfgCap4 = {
    DataObjectModelType,
    "MauCfgCap4",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfgCap5,
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfgCap4_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_MauCfgCap4_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfgCap4,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_MauCfgCap5 = {
    DataObjectModelType,
    "MauCfgCap5",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfgCap6,
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfgCap5_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_MauCfgCap5_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfgCap5,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_MauCfgCap6 = {
    DataObjectModelType,
    "MauCfgCap6",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_AutoNgtCfg,
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfgCap6_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_MauCfgCap6_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP3_MauCfgCap6,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_AutoNgtCfg = {
    DataObjectModelType,
    "AutoNgtCfg",
    (ModelNode*) &iedModel_LD0_LPCP3,
    (ModelNode*) &iedModel_LD0_LPCP3_AdminCfg,
    (ModelNode*) &iedModel_LD0_LPCP3_AutoNgtCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_AutoNgtCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP3_AutoNgtCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP3_AdminCfg = {
    DataObjectModelType,
    "AdminCfg",
    (ModelNode*) &iedModel_LD0_LPCP3,
    NULL,
    (ModelNode*) &iedModel_LD0_LPCP3_AdminCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP3_AdminCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP3_AdminCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

LogicalNode iedModel_LD0_LPCP4 = {
    LogicalNodeModelType,
    "LPCP4",
    (ModelNode*) &iedModel_LD0,
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP4_NamPlt,
};

DataObject iedModel_LD0_LPCP4_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_PhyNam,
    (ModelNode*) &iedModel_LD0_LPCP4_NamPlt_vendor,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LD0_LPCP4_NamPlt,
    (ModelNode*) &iedModel_LD0_LPCP4_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LD0_LPCP4_NamPlt,
    (ModelNode*) &iedModel_LD0_LPCP4_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LD0_LPCP4_NamPlt,
    (ModelNode*) &iedModel_LD0_LPCP4_NamPlt_lnNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_NamPlt_lnNs = {
    DataAttributeModelType,
    "lnNs",
    (ModelNode*) &iedModel_LD0_LPCP4_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPCP4_PhyNam_vendor,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LD0_LPCP4_PhyNam,
    (ModelNode*) &iedModel_LD0_LPCP4_PhyNam_model,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_PhyNam_model = {
    DataAttributeModelType,
    "model",
    (ModelNode*) &iedModel_LD0_LPCP4_PhyNam,
    (ModelNode*) &iedModel_LD0_LPCP4_PhyNam_location,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_PhyNam_location = {
    DataAttributeModelType,
    "location",
    (ModelNode*) &iedModel_LD0_LPCP4_PhyNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP4_PhyHealth_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP4_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPCP4_PhyHealth_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP4_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPCP4_PhyHealth_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP4_PhyHealth,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_RxCnt = {
    DataObjectModelType,
    "RxCnt",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP4_RxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_RxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LPCP4_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP4_RxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_RxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP4_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP4_RxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_RxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP4_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP4_RxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_RxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LPCP4_RxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_TxCnt = {
    DataObjectModelType,
    "TxCnt",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_FerPort,
    (ModelNode*) &iedModel_LD0_LPCP4_TxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_TxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LPCP4_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP4_TxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_TxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP4_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP4_TxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_TxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP4_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP4_TxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_TxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LPCP4_TxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_FerPort = {
    DataObjectModelType,
    "FerPort",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_Mau,
    (ModelNode*) &iedModel_LD0_LPCP4_FerPort_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_FerPort_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP4_FerPort,
    (ModelNode*) &iedModel_LD0_LPCP4_FerPort_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_FerPort_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP4_FerPort,
    (ModelNode*) &iedModel_LD0_LPCP4_FerPort_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_FerPort_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP4_FerPort,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_Mau = {
    DataObjectModelType,
    "Mau",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_AutoNgt,
    (ModelNode*) &iedModel_LD0_LPCP4_Mau_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_Mau_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP4_Mau,
    (ModelNode*) &iedModel_LD0_LPCP4_Mau_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_Mau_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP4_Mau,
    (ModelNode*) &iedModel_LD0_LPCP4_Mau_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_Mau_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP4_Mau,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_AutoNgt = {
    DataObjectModelType,
    "AutoNgt",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_PortNam,
    (ModelNode*) &iedModel_LD0_LPCP4_AutoNgt_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_AutoNgt_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP4_AutoNgt,
    (ModelNode*) &iedModel_LD0_LPCP4_AutoNgt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_AutoNgt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP4_AutoNgt,
    (ModelNode*) &iedModel_LD0_LPCP4_AutoNgt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP4_AutoNgt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP4_AutoNgt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_PortNam = {
    DataObjectModelType,
    "PortNam",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_PortNum,
    (ModelNode*) &iedModel_LD0_LPCP4_PortNam_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_PortNam_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP4_PortNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_255,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_PortNum = {
    DataObjectModelType,
    "PortNum",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_PortMac,
    (ModelNode*) &iedModel_LD0_LPCP4_PortNum_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_PortNum_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP4_PortNum,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_PortMac = {
    DataObjectModelType,
    "PortMac",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfg,
    (ModelNode*) &iedModel_LD0_LPCP4_PortMac_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_PortMac_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP4_PortMac,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_255,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_MauCfg = {
    DataObjectModelType,
    "MauCfg",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfgCap1,
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_MauCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_MauCfgCap1 = {
    DataObjectModelType,
    "MauCfgCap1",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfgCap2,
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfgCap1_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_MauCfgCap1_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfgCap1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_MauCfgCap2 = {
    DataObjectModelType,
    "MauCfgCap2",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfgCap3,
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfgCap2_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_MauCfgCap2_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfgCap2,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_MauCfgCap3 = {
    DataObjectModelType,
    "MauCfgCap3",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfgCap4,
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfgCap3_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_MauCfgCap3_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfgCap3,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_MauCfgCap4 = {
    DataObjectModelType,
    "MauCfgCap4",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfgCap5,
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfgCap4_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_MauCfgCap4_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfgCap4,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_MauCfgCap5 = {
    DataObjectModelType,
    "MauCfgCap5",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfgCap6,
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfgCap5_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_MauCfgCap5_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfgCap5,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_MauCfgCap6 = {
    DataObjectModelType,
    "MauCfgCap6",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_AutoNgtCfg,
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfgCap6_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_MauCfgCap6_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP4_MauCfgCap6,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_AutoNgtCfg = {
    DataObjectModelType,
    "AutoNgtCfg",
    (ModelNode*) &iedModel_LD0_LPCP4,
    (ModelNode*) &iedModel_LD0_LPCP4_AdminCfg,
    (ModelNode*) &iedModel_LD0_LPCP4_AutoNgtCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_AutoNgtCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP4_AutoNgtCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP4_AdminCfg = {
    DataObjectModelType,
    "AdminCfg",
    (ModelNode*) &iedModel_LD0_LPCP4,
    NULL,
    (ModelNode*) &iedModel_LD0_LPCP4_AdminCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP4_AdminCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP4_AdminCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

LogicalNode iedModel_LD0_LPCP5 = {
    LogicalNodeModelType,
    "LPCP5",
    (ModelNode*) &iedModel_LD0,
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP5_NamPlt,
};

DataObject iedModel_LD0_LPCP5_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_PhyNam,
    (ModelNode*) &iedModel_LD0_LPCP5_NamPlt_vendor,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LD0_LPCP5_NamPlt,
    (ModelNode*) &iedModel_LD0_LPCP5_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LD0_LPCP5_NamPlt,
    (ModelNode*) &iedModel_LD0_LPCP5_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LD0_LPCP5_NamPlt,
    (ModelNode*) &iedModel_LD0_LPCP5_NamPlt_lnNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_NamPlt_lnNs = {
    DataAttributeModelType,
    "lnNs",
    (ModelNode*) &iedModel_LD0_LPCP5_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPCP5_PhyNam_vendor,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LD0_LPCP5_PhyNam,
    (ModelNode*) &iedModel_LD0_LPCP5_PhyNam_model,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_PhyNam_model = {
    DataAttributeModelType,
    "model",
    (ModelNode*) &iedModel_LD0_LPCP5_PhyNam,
    (ModelNode*) &iedModel_LD0_LPCP5_PhyNam_location,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_PhyNam_location = {
    DataAttributeModelType,
    "location",
    (ModelNode*) &iedModel_LD0_LPCP5_PhyNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP5_PhyHealth_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP5_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPCP5_PhyHealth_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP5_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPCP5_PhyHealth_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP5_PhyHealth,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_RxCnt = {
    DataObjectModelType,
    "RxCnt",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP5_RxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_RxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LPCP5_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP5_RxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_RxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP5_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP5_RxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_RxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP5_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP5_RxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_RxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LPCP5_RxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_TxCnt = {
    DataObjectModelType,
    "TxCnt",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_FerPort,
    (ModelNode*) &iedModel_LD0_LPCP5_TxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_TxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LPCP5_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP5_TxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_TxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP5_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP5_TxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_TxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP5_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP5_TxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_TxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LPCP5_TxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_FerPort = {
    DataObjectModelType,
    "FerPort",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_Mau,
    (ModelNode*) &iedModel_LD0_LPCP5_FerPort_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_FerPort_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP5_FerPort,
    (ModelNode*) &iedModel_LD0_LPCP5_FerPort_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_FerPort_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP5_FerPort,
    (ModelNode*) &iedModel_LD0_LPCP5_FerPort_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_FerPort_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP5_FerPort,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_Mau = {
    DataObjectModelType,
    "Mau",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_AutoNgt,
    (ModelNode*) &iedModel_LD0_LPCP5_Mau_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_Mau_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP5_Mau,
    (ModelNode*) &iedModel_LD0_LPCP5_Mau_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_Mau_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP5_Mau,
    (ModelNode*) &iedModel_LD0_LPCP5_Mau_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_Mau_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP5_Mau,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_AutoNgt = {
    DataObjectModelType,
    "AutoNgt",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_PortNam,
    (ModelNode*) &iedModel_LD0_LPCP5_AutoNgt_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_AutoNgt_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP5_AutoNgt,
    (ModelNode*) &iedModel_LD0_LPCP5_AutoNgt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_AutoNgt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP5_AutoNgt,
    (ModelNode*) &iedModel_LD0_LPCP5_AutoNgt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP5_AutoNgt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP5_AutoNgt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_PortNam = {
    DataObjectModelType,
    "PortNam",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_PortNum,
    (ModelNode*) &iedModel_LD0_LPCP5_PortNam_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_PortNam_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP5_PortNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_255,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_PortNum = {
    DataObjectModelType,
    "PortNum",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_PortMac,
    (ModelNode*) &iedModel_LD0_LPCP5_PortNum_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_PortNum_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP5_PortNum,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_PortMac = {
    DataObjectModelType,
    "PortMac",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfg,
    (ModelNode*) &iedModel_LD0_LPCP5_PortMac_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_PortMac_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP5_PortMac,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_255,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_MauCfg = {
    DataObjectModelType,
    "MauCfg",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfgCap1,
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_MauCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_MauCfgCap1 = {
    DataObjectModelType,
    "MauCfgCap1",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfgCap2,
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfgCap1_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_MauCfgCap1_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfgCap1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_MauCfgCap2 = {
    DataObjectModelType,
    "MauCfgCap2",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfgCap3,
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfgCap2_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_MauCfgCap2_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfgCap2,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_MauCfgCap3 = {
    DataObjectModelType,
    "MauCfgCap3",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfgCap4,
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfgCap3_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_MauCfgCap3_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfgCap3,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_MauCfgCap4 = {
    DataObjectModelType,
    "MauCfgCap4",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfgCap5,
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfgCap4_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_MauCfgCap4_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfgCap4,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_MauCfgCap5 = {
    DataObjectModelType,
    "MauCfgCap5",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfgCap6,
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfgCap5_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_MauCfgCap5_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfgCap5,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_MauCfgCap6 = {
    DataObjectModelType,
    "MauCfgCap6",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_AutoNgtCfg,
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfgCap6_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_MauCfgCap6_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP5_MauCfgCap6,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_AutoNgtCfg = {
    DataObjectModelType,
    "AutoNgtCfg",
    (ModelNode*) &iedModel_LD0_LPCP5,
    (ModelNode*) &iedModel_LD0_LPCP5_AdminCfg,
    (ModelNode*) &iedModel_LD0_LPCP5_AutoNgtCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_AutoNgtCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP5_AutoNgtCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP5_AdminCfg = {
    DataObjectModelType,
    "AdminCfg",
    (ModelNode*) &iedModel_LD0_LPCP5,
    NULL,
    (ModelNode*) &iedModel_LD0_LPCP5_AdminCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP5_AdminCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP5_AdminCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

LogicalNode iedModel_LD0_LPCP6 = {
    LogicalNodeModelType,
    "LPCP6",
    (ModelNode*) &iedModel_LD0,
    NULL,
    (ModelNode*) &iedModel_LD0_LPCP6_NamPlt,
};

DataObject iedModel_LD0_LPCP6_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_PhyNam,
    (ModelNode*) &iedModel_LD0_LPCP6_NamPlt_vendor,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LD0_LPCP6_NamPlt,
    (ModelNode*) &iedModel_LD0_LPCP6_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LD0_LPCP6_NamPlt,
    (ModelNode*) &iedModel_LD0_LPCP6_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LD0_LPCP6_NamPlt,
    (ModelNode*) &iedModel_LD0_LPCP6_NamPlt_lnNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_NamPlt_lnNs = {
    DataAttributeModelType,
    "lnNs",
    (ModelNode*) &iedModel_LD0_LPCP6_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPCP6_PhyNam_vendor,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LD0_LPCP6_PhyNam,
    (ModelNode*) &iedModel_LD0_LPCP6_PhyNam_model,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_PhyNam_model = {
    DataAttributeModelType,
    "model",
    (ModelNode*) &iedModel_LD0_LPCP6_PhyNam,
    (ModelNode*) &iedModel_LD0_LPCP6_PhyNam_location,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_PhyNam_location = {
    DataAttributeModelType,
    "location",
    (ModelNode*) &iedModel_LD0_LPCP6_PhyNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP6_PhyHealth_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP6_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPCP6_PhyHealth_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP6_PhyHealth,
    (ModelNode*) &iedModel_LD0_LPCP6_PhyHealth_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP6_PhyHealth,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_RxCnt = {
    DataObjectModelType,
    "RxCnt",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP6_RxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_RxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LPCP6_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP6_RxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_RxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP6_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP6_RxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_RxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP6_RxCnt,
    (ModelNode*) &iedModel_LD0_LPCP6_RxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_RxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LPCP6_RxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_TxCnt = {
    DataObjectModelType,
    "TxCnt",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_FerPort,
    (ModelNode*) &iedModel_LD0_LPCP6_TxCnt_actVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_TxCnt_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LD0_LPCP6_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP6_TxCnt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_TxCnt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP6_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP6_TxCnt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_TxCnt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP6_TxCnt,
    (ModelNode*) &iedModel_LD0_LPCP6_TxCnt_pulsQty,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_TxCnt_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LD0_LPCP6_TxCnt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_FerPort = {
    DataObjectModelType,
    "FerPort",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_Mau,
    (ModelNode*) &iedModel_LD0_LPCP6_FerPort_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_FerPort_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP6_FerPort,
    (ModelNode*) &iedModel_LD0_LPCP6_FerPort_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_FerPort_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP6_FerPort,
    (ModelNode*) &iedModel_LD0_LPCP6_FerPort_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_FerPort_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP6_FerPort,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_Mau = {
    DataObjectModelType,
    "Mau",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_AutoNgt,
    (ModelNode*) &iedModel_LD0_LPCP6_Mau_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_Mau_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP6_Mau,
    (ModelNode*) &iedModel_LD0_LPCP6_Mau_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_Mau_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP6_Mau,
    (ModelNode*) &iedModel_LD0_LPCP6_Mau_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_Mau_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP6_Mau,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_AutoNgt = {
    DataObjectModelType,
    "AutoNgt",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_PortNam,
    (ModelNode*) &iedModel_LD0_LPCP6_AutoNgt_stVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_AutoNgt_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LD0_LPCP6_AutoNgt,
    (ModelNode*) &iedModel_LD0_LPCP6_AutoNgt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_AutoNgt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LD0_LPCP6_AutoNgt,
    (ModelNode*) &iedModel_LD0_LPCP6_AutoNgt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LD0_LPCP6_AutoNgt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LD0_LPCP6_AutoNgt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_PortNam = {
    DataObjectModelType,
    "PortNam",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_PortNum,
    (ModelNode*) &iedModel_LD0_LPCP6_PortNam_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_PortNam_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP6_PortNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_255,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_PortNum = {
    DataObjectModelType,
    "PortNum",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_PortMac,
    (ModelNode*) &iedModel_LD0_LPCP6_PortNum_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_PortNum_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP6_PortNum,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_PortMac = {
    DataObjectModelType,
    "PortMac",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfg,
    (ModelNode*) &iedModel_LD0_LPCP6_PortMac_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_PortMac_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP6_PortMac,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_VISIBLE_STRING_255,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_MauCfg = {
    DataObjectModelType,
    "MauCfg",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfgCap1,
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_MauCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_MauCfgCap1 = {
    DataObjectModelType,
    "MauCfgCap1",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfgCap2,
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfgCap1_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_MauCfgCap1_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfgCap1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_MauCfgCap2 = {
    DataObjectModelType,
    "MauCfgCap2",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfgCap3,
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfgCap2_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_MauCfgCap2_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfgCap2,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_MauCfgCap3 = {
    DataObjectModelType,
    "MauCfgCap3",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfgCap4,
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfgCap3_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_MauCfgCap3_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfgCap3,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_MauCfgCap4 = {
    DataObjectModelType,
    "MauCfgCap4",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfgCap5,
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfgCap4_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_MauCfgCap4_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfgCap4,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_MauCfgCap5 = {
    DataObjectModelType,
    "MauCfgCap5",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfgCap6,
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfgCap5_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_MauCfgCap5_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfgCap5,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_MauCfgCap6 = {
    DataObjectModelType,
    "MauCfgCap6",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_AutoNgtCfg,
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfgCap6_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_MauCfgCap6_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP6_MauCfgCap6,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_AutoNgtCfg = {
    DataObjectModelType,
    "AutoNgtCfg",
    (ModelNode*) &iedModel_LD0_LPCP6,
    (ModelNode*) &iedModel_LD0_LPCP6_AdminCfg,
    (ModelNode*) &iedModel_LD0_LPCP6_AutoNgtCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_AutoNgtCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP6_AutoNgtCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LD0_LPCP6_AdminCfg = {
    DataObjectModelType,
    "AdminCfg",
    (ModelNode*) &iedModel_LD0_LPCP6,
    NULL,
    (ModelNode*) &iedModel_LD0_LPCP6_AdminCfg_setVal,
    0,
    -1
};

DataAttribute iedModel_LD0_LPCP6_AdminCfg_setVal = {
    DataAttributeModelType,
    "setVal",
    (ModelNode*) &iedModel_LD0_LPCP6_AdminCfg,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_SP,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

extern ReportControlBlock iedModel_LD0_LLN0_report0;

ReportControlBlock iedModel_LD0_LLN0_report0 = {&iedModel_LD0_LLN0, "Events01", "LD0/LLN0.RP.Events", false, "battery", 1, 19, 175, 0, 0, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, NULL};







IedModel iedModel = {
    "LaptopServer",
    &iedModel_LD0,
    &iedModelds_LD0_LLN0_battery,
    &iedModel_LD0_LLN0_report0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    initializeValues
};

static void
initializeValues()
{

iedModel_LD0_LCCH1_RxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH1_RedRxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH1_TxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH2_RxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH2_RedRxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH2_TxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH3_RxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH3_RedRxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH3_TxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH4_RxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH4_RedRxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH4_TxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH5_RxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH5_RedRxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH5_TxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH6_RxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH6_RedRxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH6_TxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH7_RxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH7_RedRxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LCCH7_TxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LPCP1_NamPlt_lnNs.mmsValue = MmsValue_newVisibleString("(Tr)IEC 61850-90-4:2012");

iedModel_LD0_LPCP1_RxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LPCP1_TxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LPCP2_NamPlt_lnNs.mmsValue = MmsValue_newVisibleString("(Tr)IEC 61850-90-4:2012");

iedModel_LD0_LPCP2_RxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LPCP2_TxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LPCP3_NamPlt_lnNs.mmsValue = MmsValue_newVisibleString("(Tr)IEC 61850-90-4:2012");

iedModel_LD0_LPCP3_RxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LPCP3_TxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LPCP4_NamPlt_lnNs.mmsValue = MmsValue_newVisibleString("(Tr)IEC 61850-90-4:2012");

iedModel_LD0_LPCP4_RxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LPCP4_TxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LPCP5_NamPlt_lnNs.mmsValue = MmsValue_newVisibleString("(Tr)IEC 61850-90-4:2012");

iedModel_LD0_LPCP5_RxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LPCP5_TxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LPCP6_NamPlt_lnNs.mmsValue = MmsValue_newVisibleString("(Tr)IEC 61850-90-4:2012");

iedModel_LD0_LPCP6_RxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);

iedModel_LD0_LPCP6_TxCnt_pulsQty.mmsValue = MmsValue_newFloat(1.0);
}
