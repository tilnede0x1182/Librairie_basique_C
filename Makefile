run:
	@echo ""
	@echo "======================================"
	@echo "Execution de tous les tests"
	@echo "======================================"
	@bin/ouverture_fichier.exe
	@bin/lecture_fichier.exe
	@bin/ecriture_stdin.exe
	@bin/manipulation_chaines.exe

compile:
	@mkdir -p bin
	gcc -Wall -Wextra -std=c99 -I src/Headers/Utilitaire -o bin/ouverture_fichier.exe src/C/ouverture_fichier.c src/C/Utilitaire/io_utils.c
	gcc -Wall -Wextra -std=c99 -I src/Headers/Utilitaire -o bin/lecture_fichier.exe src/C/lecture_fichier.c src/C/Utilitaire/io_utils.c
	gcc -Wall -Wextra -std=c99 -I src/Headers/Utilitaire -o bin/ecriture_stdin.exe src/C/ecriture_stdin.c src/C/Utilitaire/io_utils.c
	gcc -Wall -Wextra -std=c99 -I src/Headers/Utilitaire -o bin/manipulation_chaines.exe src/C/manipulation_chaines.c src/C/Utilitaire/UtilString.c

compile_run: compile run

clean:
	rm -rf bin/* build/*
