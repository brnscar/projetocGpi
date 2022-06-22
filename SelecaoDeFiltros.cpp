#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;


Mat getUserImage() {
    cout << "\n\nEscreva o nome da sua imagem e a extens�o dela? ex:'nome.extens�o'" << endl;
    string caminho_imagem;
    cin >> caminho_imagem;
    Mat read_teste = imread(caminho_imagem);
    return read_teste;
}

void setKernell(Mat img) {

    Mat kernel1 = (Mat_<double>(3, 3) << 0, 0, 0, 0, 1, 0, 0, 0, 0);

    Mat identity;
    filter2D(img, identity, -1, kernel1, Point(-1, -1), 0, 4);
    imshow("Original", img);
    imshow("Editada", identity);
    waitKey();
    imwrite("ml_kernell.png", identity);
    destroyAllWindows();
}

void setBlur(Mat img) {
    // Blurred using kernel
    // Initialize matrix with all ones
    Mat kernel2 = Mat::ones(5, 5, CV_64F);
    // Normalize the elements
    kernel2 = kernel2 / 25;
    Mat identity;
    filter2D(img, identity, -1, kernel2, Point(-1, -1), 0, 4);
    imshow("Original", img);
    imshow("Editada", identity);
    imwrite("ml_blur.png", identity);
    waitKey();
    destroyAllWindows();


}

void setSharpening(Mat img) {
    // Apply sharpening using kernel
    Mat sharp_img;
    Mat kernel3 = (Mat_<double>(3, 3) << 0, -1, 0,
        -1, 5, -1,
        0, -1, 0);
    filter2D(img, sharp_img, -1, kernel3, Point(-1, -1), 0, BORDER_DEFAULT);
    imshow("Original", img);
    imshow("Editada", sharp_img);
    imwrite("ml_sharpening.png", sharp_img);
    waitKey();
    destroyAllWindows();

}

void setMediumBlur(Mat img) {
    // Apply Median Blur
    Mat median_blurred;
    medianBlur(img, median_blurred, (5, 5));
    imshow("Original", img);
    imshow("Editada", median_blurred);
    imwrite("ml_medium_blur.png", median_blurred);
    waitKey();
    destroyAllWindows();

}

int main() {
    setlocale(LC_ALL, "portuguese");
    int num;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    cout << "Retrika 2.0" << endl;
    cout << "Selecione uma imagem do seu computador e escolha dentre os poss�veis  filtros o que fica melhor na sua foto!" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n" << endl;


    cout << "Selecione uma imagem de alguma pasta do seu computador para altera��o de filtro.(Exemplo: C:\imagens\exemplo.png)" << endl;

    
    cout << "Filtros:\n 1-Kernell\n 2-Blur.\n 3-Sherping.\n 4-Medium blur" << endl;
    cin >> num;
    string caminho = "ml.png";
    switch (num) {
    case 1:
    {
        cout << "kernell selecionado\n\n" << endl;
        Mat img = getUserImage();
        setKernell(img);
        break;
    }
    case 2:
    {
        cout << "blur selecionado\n\n" << endl;
        Mat img = getUserImage();
        setBlur(img);
        break;
    }
    case 3:
    {  
        cout << "Sherping selecionado\n\n" << endl;
        Mat img = getUserImage();
        setSharpening(img);
        break;
    }
    case 4:
    {
        cout << "Medium selecionado\n\n" << endl;
        Mat img = getUserImage();
        setMediumBlur(img);
        break;
    }
    default:
        cout << "Erro filtro n�o encontrado ou n�o existente";
        break;
    }


    waitKey(0);

    return 0;

}