// schemamanager.h
// Created 12/29/2009 by RJ Ryan (rryan@mit.edu)

#ifndef SCHEMAMANAGER_H
#define SCHEMAMANAGER_H

#include <QSqlDatabase>

#include "preferences/usersettings.h"
#include "library/dao/settingsdao.h"

class SchemaManager {
  public:
    static const QString SETTINGS_VERSION_STRING;
    static const QString SETTINGS_MINCOMPATIBLE_STRING;

    enum Result {
        RESULT_OK,
        RESULT_BACKWARDS_INCOMPATIBLE,
        RESULT_UPGRADE_FAILED,
        RESULT_SCHEMA_ERROR
    };

    explicit SchemaManager(const QSqlDatabase& database);

    int getCurrentVersion() const {
        return m_currentVersion;
    }

    bool isBackwardsCompatibleWithVersion(int targetVersion) const;

    Result upgradeToSchemaVersion(
            const QString& schemaFilename,
            int targetVersion);

  private:
    QSqlDatabase m_database;
    SettingsDAO m_settingsDao;

    int m_currentVersion;
};

#endif /* SCHEMAMANAGER_H */
