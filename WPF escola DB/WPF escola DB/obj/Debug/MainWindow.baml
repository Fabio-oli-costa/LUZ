   M S B A M L   `   `   `  ����H  DWPF escola DB, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null-clr-namespace:WPF_escola_DBWPF_escola_DB  5   	       WPF_escola_DB.MainWindow   5   	   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   -localclr-namespace:WPF_escola_DB     5   	     � Title$  
MainWindow��5   	   $	��450��6   $	��800��6)   .��5	      � .+�5
   
   �� -   5        $��ListviewAlunos��5
      $��	0,205,0,0q�6w   $��Center=�6�   $	��800��6�    J� RenderTransformOrigin$ 0.5,0.5&�6�   ��6)   �� *listaAlunos+ �� SelectedItem 6M   �� *alunoSelecionado+z�5      V� 5      .~�5      �� �� 5       �� AngleY$ 0.071Q�6$   �� 5      T� 5       T� Y$ 0.499Q�6)   5       �� View 5      �� 5      .P�5      ��  �� DisplayMemberBinding 6%   �� *NomeCompleto+�� 5       6%   �� *
CodAluno+�� 5       6%   �� *Serie+5      5      �� 5   
   $��Remover Aluno��6   $
��Left=�6D   $	��Top=�6_   $��531,111,0,0q�6w   $��40��6�   $	��108��6�   ��6)   �� *remove+6�   �� 5   
   $��Adicionar Aluno��6   $
��Left=�6C   $	��Top=�6^   $��166,111,0,0q�6v   $	��108��6�   $��40��6�   ��6+   �� *add+6�   �� 5   
   $��Atualizar Cadastro��6   $��Center=�6K   $��351,111,333,0q�6h   $	��Top=�6   $��40��6�   $	��108��6�   $ 
1.26,0.575&�6�   ��6.   �� *
atualiza+6�   �� 5   
   $��HELLO WORLD!!��6   $��Center=�6(   $��31��6E   $��0,15,0,0q�6Q   $	��Top=�6c   $	��801��6{   ���	#FF1C84F7
���   �$��16(�6�   $ 0.5,0.5&�6�   $��5,5,5,5q�6�   $��Center=�6�    � IsSharedSizeScope . $��Center=�61  $��Arial Black)�6U  z�5      V� 5       .~�5!      �� �� 5"      �� 5#       �� Angle$ 0.245Q�6&   T� 5$      5%      5'      5(      5)      