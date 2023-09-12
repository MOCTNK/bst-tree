### Лабораторная работа №2 по дисциплине: «Алгоритмы и структуры данных»
Освоение технологии реализации ассоциативных коллекций на примере АТД «Двоичное дерево поиска»
#### Вариант
Алгоритмы операций поиска, вставки и удаления реализуются в рекурсивной форме
#### Задание
Спроектировать, реализовать и провести тестовые испытания АТД «BST-дерево» (Binary Search Tree – BST) для коллекции, содержащей ключи и данные произвольного типа. Тип ключа и тип данных задаются параметрами шаблона класса BST-дерева.
В формате АТД BST-дерево представляется как упорядоченное, иерархическое, ассоциативное множество элементов, между которыми существуют структурные отношения «предки–левые потомки–правые потомки».
Интерфейс АТД «BST-дерево» включает следующие операции:
- конструктор,
- конструктор копирования,
- деструктор,
- опрос размера дерева,
- очистка дерева,
- проверка дерева на пустоту,
- доступ по чтению/записи к данным по ключу,
- включение данных с заданным ключом,
- удаление данных с заданным ключом,
- формирование списка ключей в дереве в порядке обхода узлов по схеме, заданной в варианте задания,
- дополнительная операция, заданная в варианте задания,
- запрос прямого итератора, установленного на узел дерева с минимальным ключом begin(),
- запрос обратного итератора, установленного на узел дерева с максимальным ключом rbegin(),
- запрос «неустановленного» прямого итератора end(),
- запрос «неустановленного» обратного итератора rend(). Операции прямого и обратного итератора выполняются по схеме симметричного обхода элементов дерева L → t → R:
  - операция доступа по чтению и записи к данным текущего узла * ,
  - операция перехода к следующему (для обратного – к предыдущему) по ключу узлу в дереве ++ ,
  - операция перехода к предыдущему (для обратного – к следующему) по ключу узлу в дереве -- ,
  - проверка равенства однотипных итераторов == ,
  - проверка неравенства однотипных итераторов != . 