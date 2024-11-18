#include <vector>
#include "TRandom3.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "RooRealVar.h"
#include "RooGaussian.h"

int plotGaussian() {
    RooRealVar x("x", "x", 0, -10, 10);
    RooRealVar mean("mean", "mean da gaussian", 0, -10, 1);
    RooRealVar width("width", "width", 3, 0.1, 10);
    RooGaussian g("g", "gaussian", x, mean, width);
    RooPlot* frame = x.frame();
    g.plotOn(frame);
    TCanvas *c = new TCanvas("c1", "plot da gaussiana", 800, 600);


    frame->Draw();
    c->Draw();
    c->SaveAs("gauss.png");
    return 0;

}