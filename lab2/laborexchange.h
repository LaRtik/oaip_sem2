#ifndef LABOREXCHANGE_H
#define LABOREXCHANGE_H
#include <vector>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>

using namespace std;


class LaborExchange
{
public:
    LaborExchange();

    struct Firm
    {
        QString name = "Add new...", specialty, position;
        double salary;
        int vacationDays;
        bool needHigherEducation;
        int needMinAge;
        int needMaxAge;
    };

    vector <Firm> listFirm;
    struct Candidate
    {
        QString fullName = "Add new...";
        QString dateOfBirth = "01.01.1990";
        QString specialty = "Informatics";
        bool higherEducation = 1;
        QString desirePosition = "Programmer";
        double minSalary = 500;
    };
    vector <Candidate> listCandidate;

    void addCandidatesFromFile(QFile file)
    {
        Candidate cand;
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(0, "Ошибка", "Невозможно открыть файл");
        }
        while (!file.atEnd())
        {
            cand.fullName = file.readLine();
            cand.dateOfBirth = file.readLine();
            cand.specialty = file.readLine();
            cand.higherEducation = file.readLine().toInt();
            cand.desirePosition = file.readLine();
            cand.minSalary = file.readLine().toDouble();
            cand.fullName.chop(1);
            cand.dateOfBirth.chop(1);
            cand.specialty.chop(1);
            cand.desirePosition.chop(1);
            addNewCandidate(cand);
        }
        addNewEmptyCandidate();
        file.close();
    }

    void addFirmFromFile(QFile file)
    {
        Firm firm;
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(0, "Ошибка", "Невозможно открыть файл");
        }
        while (!file.atEnd())
        {
            firm.name = file.readLine();
            firm.specialty = file.readLine();
            firm.position = file.readLine();
            firm.salary = file.readLine().toDouble();
            firm.vacationDays = file.readLine().toInt();
            firm.needHigherEducation = file.readLine().toInt();
            firm.needMinAge = file.readLine().toInt();
            firm.needMaxAge = file.readLine().toInt();
            firm.name.chop(1);
            firm.specialty.chop(1);
            firm.position.chop(1);
            addNewFirm(firm);
        }
        addNewEmptyFirm();
        file.close();
    }

    void sortCandidatesByName()
    {
        deleteCandidate(listCandidate.size() - 1);
        sort(listCandidate.begin(), listCandidate.end(), [](Candidate a, Candidate b)
             {
                 return a.fullName < b.fullName;
             });
        addNewEmptyCandidate();
    }

    void sortFirmsByName()
    {
        deleteFirm(listFirm.size() - 1);
        sort(listFirm.begin(), listFirm.end(), [](Firm a, Firm b)
             {
                 return a.name < b.name;
             });
        addNewEmptyFirm();
    }



    void addNewCandidate(Candidate cand)
    {
        listCandidate.push_back(cand);
    }

    void addNewFirm(Firm firm)
    {
        listFirm.push_back(firm);
    }

    void addNewEmptyCandidate()
    {
        Candidate cand;
        listCandidate.push_back(cand);
    }

    void addNewEmptyFirm()
    {
        Firm firm;
        listFirm.push_back(firm);
    }

    bool isMatchFirm(int firmIndex, int candIndex)
    {
        if (listFirm[firmIndex].salary < listCandidate[candIndex].minSalary) return false;
        if (listFirm[firmIndex].specialty != listCandidate[candIndex].specialty) return false;
        if (listFirm[firmIndex].position != listCandidate[candIndex].desirePosition) return false;
        if (listFirm[firmIndex].needHigherEducation && !listCandidate[candIndex].higherEducation) return false;
        if (getAge(listCandidate[candIndex].dateOfBirth) > listFirm[firmIndex].needMaxAge ||
                getAge(listCandidate[candIndex].dateOfBirth) < listFirm[firmIndex].needMinAge) return false;
        return true;
    }

    int getAge(QString date)
    {
        QDateTime _date = QDateTime::fromString(date, "dd.mm.yyyy");
        int m = _date.secsTo(QDateTime::currentDateTime());
        return m / 31536000;
    }

    QString getAvailablePositions(int index)
    {
        QString result;
        for (int i = 0; i < (int)listFirm.size(); i++)
        {
            if (isMatchFirm(i, index))
            {
                result += "Должность " + listFirm[i].position + " в фирме " + listFirm[i].name + ".\n";
            }
        }
        return result;
    }

    void rewriteCandidates(QFile file)
    {
        if (!file.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(0, "Ошибка", "Невозможно открыть файл");
        }

        QTextStream out(&file);
        for (int i = 0; i < (int)listCandidate.size(); i++)
        {
            if (listCandidate[i].fullName == "Add new...") break;
            out << listCandidate[i].fullName << '\n';
            out << listCandidate[i].dateOfBirth << '\n';
            out << listCandidate[i].specialty << '\n';
            out << listCandidate[i].higherEducation << '\n';
            out << listCandidate[i].desirePosition << '\n';
            out << listCandidate[i].minSalary << '\n';
        }

        file.close();
    }

    void rewriteFirms(QFile file)
    {
        if (!file.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(0, "Ошибка", "Невозможно открыть файл");
        }

        QTextStream out(&file);
        for (int i = 0; i < (int)listFirm.size(); i++)
        {
            if (listFirm[i].name == "Add new...") break;
            out << listFirm[i].name << "\n";
            out << listFirm[i].specialty << "\n";
            out << listFirm[i].position << "\n";
            out << listFirm[i].salary << "\n";
            out << listFirm[i].vacationDays << "\n";
            out << listFirm[i].needHigherEducation << "\n";
            out << listFirm[i].needMinAge << "\n";
            out << listFirm[i].needMaxAge << "\n";
        }
        file.close();
    }


    void deleteCandidate(int index)
    {
        listCandidate.erase(listCandidate.begin() + index);
    }

    void deleteFirm(int index)
    {
        listFirm.erase(listFirm.begin() + index);
    }

    QString getScarceJobs()
    {
        QString result;
        for (int i = 0; i < (int)listFirm.size(); i++)
        {
            bool scarce = true;
            if (listFirm[i].name == "Add new...") break;
            for (int j = 0; j < (int)listCandidate.size(); j++)
            {
                if (isMatchFirm(i, j))
                {
                    scarce = false;
                    break;
                }
            }

            if (scarce)
            {
                result += listFirm[i].name + '\n';
            }
        }
        return result;
    }
};

#endif // LABOREXCHANGE_H
