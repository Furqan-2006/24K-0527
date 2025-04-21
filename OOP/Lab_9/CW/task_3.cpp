#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PatientRecord
{
private:
    string patientID;
    string name;
    string dateOfBirth;

    vector<string> medicalHistory;
    vector<string> currentTreatment;
    vector<string> billingDetails;

public:
    PatientRecord(string id, string n, string dob)
        : patientID(id), name(n), dateOfBirth(dob) {}

    string getPublicData() const
    {
        return "Patient ID: " + patientID + ", Name: " + name + ", DOB: " + dateOfBirth;
    }

private:
    vector<string> getMedicalData() const
    {
        return medicalHistory;
    }

    void updateMedicalHistory(const string &entry)
    {
        medicalHistory.push_back(entry);
    }

    void addTreatment(const string &treatment)
    {
        currentTreatment.push_back(treatment);
    }

    void addBillingDetails(const string &bill)
    {
        billingDetails.push_back(bill);
    }

    vector<string> getBillingDetails() const
    {
        return billingDetails;
    }

    friend class Doctor;
    friend class Billing;
};

class Doctor
{
public:
    void updatePatientRecord(PatientRecord &record, const string &diagnosis, const string &treatment)
    {
        record.updateMedicalHistory(diagnosis);
        record.addTreatment(treatment);
        cout << "Doctor updated patient record.\n";
    }

    void viewMedicalHistory(const PatientRecord &record)
    {
        vector<string> history = record.getMedicalData();
        cout << "Medical History:\n";
        for (const string &entry : history)
            cout << "- " << entry << endl;
    }
};

class Billing
{
public:
    void addInvoice(PatientRecord &record, const string &invoice)
    {
        record.addBillingDetails(invoice);
        cout << "Billing entry added.\n";
    }

    void viewBilling(const PatientRecord &record)
    {
        vector<string> bills = record.getBillingDetails();
        cout << "Billing Details:\n";
        for (const string &entry : bills)
            cout << "- " << entry << endl;
    }
};

class Receptionist
{
public:
    void accessPatientInfo(const PatientRecord &record)
    {
        cout << "Receptionist sees: " << record.getPublicData() << endl;

        // The following lines are illegal and will not compile:
        // record.getMedicalData();
        // record.updateMedicalHistory("Something");
        // record.addBillingDetails("Invoice");

        // Uncommenting them will cause a compilation error
    }
};

int main()
{
    PatientRecord p1("P001", "John Doe", "1990-06-15");

    Doctor doc;
    doc.updatePatientRecord(p1, "Diabetes Type II", "Metformin 500mg");
    doc.viewMedicalHistory(p1);

    Billing biller;
    biller.addInvoice(p1, "Consultation Fee: PKR 2000");
    biller.viewBilling(p1);

    Receptionist rec;
    rec.accessPatientInfo(p1);

    return 0;
}
