#include "TF1.h"
#include "TMath.h"
#include "TGraph.h"
#include "TCanvas.h"

Double_t foo(Double_t *x, Double_t *par) {
    return TMath::Sin(x[0]) * TMath::Cos(x[0]);
}

void seno() {
    TF1 *f = new TF1("funcao_definida", foo, 0, 10, 0);
    TGraph *graph = new TGraph(f);
    graph->SetTitle("Gráfico de sen * cos");
    graph->GetXaxis()->SetTitle("Eixo X");
    TCanvas *c = new TCanvas("canvas", "titulo??", 800, 600);
    graph->Draw("AL");
    c->SaveAs("seno.png");
}