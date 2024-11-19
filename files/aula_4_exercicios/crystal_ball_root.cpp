#include "RooCBShape.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooPlot.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TStyle.h"
#include "TPaveText.h"

void crystal_ball_root() {
    const int nPoints = 1000;
    const double xmin = -10;
    const double xmax = 10;

    RooRealVar x("x", "x", xmin, xmax);

    RooRealVar mean("mean", "mean", 0);
    RooRealVar sigma("sigma", "sigma", 1);
    RooRealVar alpha("alpha", "alpha", 0.5);
    RooRealVar n("n", "n", 20);

    RooCBShape cb("cb", "Crystal Ball", x, mean, sigma, alpha, n);
    RooDataSet* data = cb.generate(x, nPoints);
    TCanvas* c = new TCanvas("c", "Crystal Ball", 800, 600);
    RooPlot* frame = x.frame();
    frame->SetTitle("Crystal Ball Function");
    data->plotOn(frame);
    cb.plotOn(frame);

    frame->GetYaxis()->SetTitleOffset(1.4);
    gStyle->SetOptStat(0);

    TPaveText* infoBox = new TPaveText(0.6, 0.7, 0.9, 0.9, "NDC");
    infoBox->SetFillColor(0);
    infoBox->SetBorderSize(1);
    infoBox->AddText(Form("Mean: %.2f", mean.getVal()));
    infoBox->AddText(Form("Sigma: %.2f", sigma.getVal()));
    infoBox->AddText(Form("Alpha: %.2f", alpha.getVal()));

    frame->Draw();
    infoBox->Draw();
    c->SaveAs("crystal_ball_root.png");


}