#include "TF1.h"
#include "TMath.h"
#include "TGraph.h"
#include "TCanvas.h"

Double_t foo_p0(Double_t *x, Double_t *par) {
    const float p0 = 1;
    const float p1 = 2;
    return p0 * TMath::Sin( p1 * x[0]) / x[0];
}

void exercicios_aula_3() {
    TF1 *f = new TF1("funcao_definida", foo_p0, 0, 10, 0);
    TGraph *graph = new TGraph(f);
    graph->SetTitle("Grafico do exercicio 1");
    graph->GetXaxis()->SetTitle("Eixo X");
    TCanvas *c = new TCanvas("canvas", "titulo??", 800, 600);
    graph->Draw("AL");
    c->SaveAs("exercicio_1_em_cpp.png");
}