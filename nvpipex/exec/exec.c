/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:10:50 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/25 18:11:46 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*EXECUTION

		INITIALISER UN TABLEAU DE PID = pid[2]
		CREER UNE PREMIERE FORK

			FORMATER CHILD EN FONCTION DE SA POSITION (1ER OU 2EME)

			GERER LES REDIRECTIONS

				INITALISER IN_FD ET OUT_FD

				AFFECTER A  IN_FD -> INFILE_FD SI 1ER CHILD
				AFFECTER A  OUT_FD -> PIPE[0] SI 1ER CHILD

			SI ERREUR (IN_FD < 0 OU OUT_FD < 0)
				ERREUR (FREE ET EXIT) /!\ ON EST TOUJOUR DANS UN CHILD
			DUP2(INFILEFD, STDIN)
			DUP2(OUTFILEFD, STDOUT)
			FERMER TOUT LE RESTE

			CREER L'EXECUTIION

				FAIRE PASSER  DANS EXECVE
				GERER LES CAS D'ERREURS OU EXECVE ECHOUE

		CREER UNE DEUXIEME FORK

			FORMATER CHILD EN FONCTION DE SA POSITION (1ER OU 2EME)

				GERER LES REDIRECTIONS

				INITALISER IN_FD ET OUT_FD

				AFFECTER A  IN_FD -> PIPE[1] SI 2EME CHILD
				AFFECTER A  OUT_FD -> OUTFILE_FD SI 2EME CHILD

			SI ERREUR (IN_FD < 0 OU OUT_FD < 0)
				ERREUR (FREE ET EXIT) /!\ ON EST TOUJOUR DANS UN CHILD
			DUP2(INFILEFD, STDIN)
			DUP2(OUTFILEFD, STDOUT)
			FERMER TOUT LE RESTE

			CREER L'EXECUTIION

				FAIRE PASSER  DANS EXECVE
				GERER LES CAS D'ERREURS OU EXECVE ECHOUE

	PENDANT CE TEMPS LA DANS LE PARENT :

		ON COMMENCE PAR TOUT FERMER
		ON ATT POUR LES 2 PROCESSUS DE SE TERMINER
		ON AFFECTE A STATUS LA VALEUR DE RETOUR DE LA DERNIERE COMMANDE RECU PAR WAITPID
		ON RETURN
		*/