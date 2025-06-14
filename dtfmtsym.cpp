diff --git a/deps/icu-small/source/i18n/dtfmtsym.cpp b/deps/icu-small/source/i18n/dtfmtsym.cpp
index 339db48d..a1b2c3f1 100644
--- a/deps/icu-small/source/i18n/dtfmtsym.cpp
+++ b/deps/icu-small/source/i18n/dtfmtsym.cpp
@@ -530,22 +530,22 @@ void DateFormatSymbols::dispose() {
     delete[] fStandaloneShortQuarters;
     delete[] fStandaloneNarrowQuarters;
     delete[] fLeapMonthPatterns;
-    delete[] fShortYearNames;
-    delete[] fShortZodiacNames;
-    delete[] fAbbreviatedDayPeriods;
-    delete[] fWideDayPeriods;
-    delete[] fNarrowDayPeriods;
-    delete[] fStandaloneAbbreviatedDayPeriods;
-    delete[] fStandaloneWideDayPeriods;
-    delete[] fStandaloneNarrowDayPeriods;
-
-    delete actualLocale;
-    delete validLocale;
-    validLocale = nullptr;
+    delete[] fShortYearNames; fShortYearNames = nullptr;
+    delete[] fShortZodiacNames; fShortZodiacNames = nullptr;
+    delete[] fAbbreviatedDayPeriods; fAbbreviatedDayPeriods = nullptr;
+    delete[] fWideDayPeriods; fWideDayPeriods = nullptr;
+    delete[] fNarrowDayPeriods; fNarrowDayPeriods = nullptr;
+    delete[] fStandaloneAbbreviatedDayPeriods; fStandaloneAbbreviatedDayPeriods = nullptr;
+    delete[] fStandaloneWideDayPeriods; fStandaloneWideDayPeriods = nullptr;
+    delete[] fStandaloneNarrowDayPeriods; fStandaloneNarrowDayPeriods = nullptr;
+
+    delete actualLocale; actualLocale = nullptr;
+    delete validLocale; validLocale = nullptr;
 }
 
 void DateFormatSymbols::disposeZoneStrings() {
     if (fZoneStrings) {
         for (int32_t row = 0; row < fZoneStringsRowCount; ++row) {
@@ -1023,6 +1023,30 @@ DateFormatSymbols::DateFormatSymbols(const DateFormatSymbols& other)
 
 DateFormatSymbols::DateFormatSymbols(UErrorCode& status)
     : UObject()
+    , fEras(nullptr)
+    , fErasCount(0)
+    // ... initialize ALL pointers to nullptr ...
+    , fLeapMonthPatterns(nullptr)
+    , fLeapMonthPatternsCount(0)
+    , fShortYearNames(nullptr)
+    , fShortYearNamesCount(0)
+    , fShortZodiacNames(nullptr)
+    , fShortZodiacNamesCount(0)
+    , fAbbreviatedDayPeriods(nullptr)
+    , fAbbreviatedDayPeriodsCount(0)
+    , fWideDayPeriods(nullptr)
+    , fWideDayPeriodsCount(0)
+    , fNarrowDayPeriods(nullptr)
+    , fNarrowDayPeriodsCount(0)
+    , fStandaloneAbbreviatedDayPeriods(nullptr)
+    , fStandaloneAbbreviatedDayPeriodsCount(0)
+    , fStandaloneWideDayPeriods(nullptr)
+    , fStandaloneWideDayPeriodsCount(0)
+    , fStandaloneNarrowDayPeriods(nullptr)
+    , fStandaloneNarrowDayPeriodsCount(0)
+    , fZoneStrings(nullptr)
+    , fLocaleZoneStrings(nullptr)
+    , actualLocale(nullptr)
+    , validLocale(nullptr)
 {
   initializeData(Locale::getDefault(), nullptr, status, true);
 }
