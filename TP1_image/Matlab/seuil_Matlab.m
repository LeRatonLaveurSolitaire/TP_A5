close all;

%Ouverture d'une image au format couleur
ima=single(imread('../Image/ferrari.jpg'));
ima=ima./255;

%Affichage d'une image couleur avec image
figure('name','RGB in','numbertitle','off');image(ima);


%Taille d'une image
taille=size(ima);
display(taille);

ima_r=ima(:,:,1);
ima_g=ima(:,:,2);
ima_b=ima(:,:,3);

%Affichage d'un niveau de couleur de l'image 
figure('name','R','numbertitle','off');imagesc(ima_r);colormap gray  %Niveau de rouge
figure('name','G','numbertitle','off');imagesc(ima_g);colormap gray  %Niveau de vert
figure('name','B','numbertitle','off');imagesc(ima_b);colormap gray  %Niveau de bleu

%Taille d'une image
taille=size(ima);
display(taille);



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%tic toc pour mesurer le temps de calcul  
tic;  

mu_r = ima_r ./sqrt( ima_g.^2 + ima_b.^2 + ima_r.^2);
mu_r_seuil = mu_r > 0.7;
ima_seuil = ima .* mu_r_seuil;

ima_g_out = ima_g .* (1 -mu_r_seuil) + ima_r .* mu_r_seuil ;

ima_out=ima;
ima_out(:,:,2) = ima_g_out;
        

toc;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


figure('name','seuil','numbertitle','off');image(ima_seuil);
figure('name','RGB out','numbertitle','off');image(ima_out);

%Sauvegarde d'une image au format jpg
imwrite(ima_out,'../Image/ferrari_out.jpg','jpg');



%Sauvegarde d'une image au format raw
fid = fopen('../Image/ferrari_out.raw', 'w');
fwrite(fid, ima_out, 'single');
fclose(fid);

