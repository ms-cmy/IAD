#include <vector>
#include "TRandom3.h"
#include "TH1F.h"
#include "TCanvas.h"


void exemplo_1() {
    TRandom *rand = new TRandom();
    TH1F *hist = new TH1F("Nome", "Exemplo Trandom", 100, 0, 10);
    std::vector<Double_t> randomValues;
    for (int i=0; i<1000; ++i) {
        Double_t N = rand->Uniform(0, 10);
        hist->Fill(N);
        randomValues.push_back(N);
    }
    TCanvas *c = new TCanvas("canvas", "random example", 800, 600);
    hist->Draw();
    c->SaveAs("hist.png");
}