#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "InvertedIndex.h"

#include <iostream>

QVector<species> speciesList;

QVector<species> readSpeciesFromCSV(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return speciesList;
    }

    QTextStream in(&file);
    // Skip header line
    in.readLine();
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');
        if (fields.size() == 12) { // Assuming 11 features and 1 title
            species sp;
            sp.title = fields[0].toStdString();
            for (int i = 0; i < 11; ++i) {
                sp.features[i] = (fields[i + 1].trimmed().toLower() == "yes");
            }
            speciesList.append(sp);
        }
    }

    // // Print the species list
    // for (const auto& sp : speciesList) {
    //     std::cout << "Title: " << sp.title << std::endl;
    //    /* std::cout << "Features:" << std::endl;
    //     for (int i = 0; i < 11; ++i) {
    //         std::cout << (sp.features[i] ? "Yes" : "No") << std::endl;
    //     }*/
    //     std::cout << std::endl;
    // }

    file.close();
    return speciesList;
}

species Species1, Species2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString filePath = "/Users/ifrahchishti/Downloads/ds2_proj/proj_gui/data.csv";

    QVector<species> speciesList = readSpeciesFromCSV(filePath);

    // Iterate over the species list and add each title to the QComboBox
    for (const auto& sp : speciesList) {
        ui->comboBoxSpecies1->addItem(QString::fromStdString(sp.title));
        ui->comboBoxSpecies2->addItem(QString::fromStdString(sp.title));
    }

    // qDebug() << Species1 << ' ' << Species2;

}

MainWindow::~MainWindow()
{
    delete ui;
}

QStringList readFirstColumn(const QString& filePath) {
    QStringList firstColumnValues;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return firstColumnValues;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList columns = line.split(","); // Split line into columns using comma as delimiter
        if (!columns.isEmpty()) {
            QString firstColumn = columns.first(); // Access the first column
            firstColumnValues.append(firstColumn); // Append value to list
        }
    }

    file.close();
    return firstColumnValues;
}


void MainWindow::on_pushButton_clicked()
{

    // species* Species1 = nullptr;
    // species* Species2 = nullptr;
    // for (const auto& sp : speciesList) {
    //     if (sp.title == Species1.toStdString()) {
    //         species1 = &sp;
    //     }
    //     if (sp.title == Species2.toStdString()) {
    //         species2 = &sp;
    //     }
    // }

    inverted_index index;

    double similarity_score = index.compare_species(Species1, Species2);
    qDebug() << "Similarity score between " << Species1.title << " and " << Species2.title << ": " << similarity_score;

    // Check if both species were found
    // if (Species1 && Species2) {
    //     // Species found, perform further operations
    //     // For example, calculate similarity score
    //     double similarity_score = index.compare_species(*species1, *species2);
    //     qDebug() << "Similarity score between " << Species1 << " and " << Species2 << ": " << similarity_score;
    // } else {
    //     // Species not found
    //     qDebug() << "One or both species not found in the list.";
    // }

    // QString filePath = "/Users/ifrahchishti/Downloads/ds2_proj/proj_gui/data.csv";
    // QStringList firstColumnValues = readFirstColumn(filePath);
    // qDebug() << "First column values:" << firstColumnValues;

    // QString filePath = "./data.csv";
    // qDebug() << "Attempting to open file:" << QDir::current().filePath(filePath);
    // QStringList firstColumnValues = readFirstColumn(filePath);
    // qDebug() << "First column values:" << firstColumnValues;

    // Print the species list
    // for (const auto& sp : speciesList) {
    //     std::cout << "Title: " << sp.title << std::endl;
    //     std::cout << "Features:" << std::endl;
    //     for (int i = 0; i < 11; ++i) {
    //         std::cout << (sp.features[i] ? "Yes" : "No") << std::endl;
    //     }
    //     std::cout << std::endl;
    // }

    // species species1;
    // species1.title = "Human";
    // species1.features[3] = true; // bipedaism
    // species1.features[6] = true; // placenta
    // species1.features[9] = true; // big_eyes

    // species species2;
    // species2.title = "Cat";
    // species2.features[0] = true; // flat_nails
    // species2.features[1] = true; // olfactory
    // species2.features[9] = true; // big_eyes

    // // Create an inverted_index object if needed

    // // Calculate similarity score
    // double similarity_score = index.compare_species(species1, species2);

    // // Output the similarity score
    // std::cout << "Similarity score between " << species1.title << " and " << species2.title << ": ";
    // std::cout << similarity_score << std::endl;
    // // this->setText(similarity_score)
    // // ui->label->setText(similarity_score);
    ui->label->setText(QString::number(similarity_score));

}



void MainWindow::on_comboBoxSpecies1_activated(int index)
{
    qDebug() << "on_comboBoxSpecies1_activated function called.";
    // Species2 = ui->comboBoxSpecies2->currentText();
    QString currentText = ui->comboBoxSpecies1->currentText();
    // std::cout << currenttext << std::endl;
    // qDebug() << currentText;
    for (const auto& sp : speciesList) {
        if (QString::fromStdString(sp.title) == currentText) {
            Species1 = sp; // Assign the selected species to Species1
            break;
        }
    }
    qDebug() << Species1.title;

}

void MainWindow::on_comboBoxSpecies2_activated(int index)
{
    qDebug() << "on_comboBoxSpecies2_activated function called.";
    // Species2 = ui->comboBoxSpecies2->currentText();
    QString currentText = ui->comboBoxSpecies2->currentText();
    // std::cout << currenttext << std::endl;
    // qDebug() << currentText;
    for (const auto& sp : speciesList) {
        if (QString::fromStdString(sp.title) == currentText) {
            Species2 = sp; // Assign the selected species to Species1
            break;
        }
    }
    qDebug() << Species2.title;

}

