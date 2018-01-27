# $NetBSD: Makefile,v 1.1 2013/05/10 13:20:49 francksys Exp $
#

DISTNAME=	choosefont-0.3
CATEGORIES=	x11
MASTER_SITES=	http://downloads.sourceforge.net/project/choosefont/choosefont/choosefont-0.3/

MAINTAINER=	francksys@free.fr
HOMEPAGE=	http://choosefont.sourceforge.net/
COMMENT=	Choosefont permit you to choose fonts out of a big amount of fonts
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
DEPENDS+=	tk-Tix>=8.4.3:../../x11/tk-Tix
USE_TOOLS+=	tclsh:run
NO_BUILD=	yes

INSTALLATION_DIRS=	bin lib/x11/choosefont lib/x11/choosefont/src lib/x11/choosefont/locale
INSTALLATION_DIRS+=	lib/x11/choosefont/src/output

REPLACE_INTERPRETER+=	tclsh
REPLACE.tclsh.old=	.*bash
REPLACE.tclsh.new=	${PREFIX}/bin/tclsh
REPLACE_FILES.tclsh=	choosefont.tcl

do-install:
	cd ${WRKSRC} && for file in Makefile TODO INSTALL Readme Changes CONTACT COPYING; do \
				${INSTALL_DATA} "$$file" ${DESTDIR}${PREFIX}/lib/x11/choosefont; \
			done
	${INSTALL_SCRIPT} ${WRKSRC}/choosefont.tcl ${DESTDIR}${PREFIX}/lib/x11/choosefont

	cd ${WRKSRC}/src && for file in config.tcl font.tcl fontdialog.tcl; do \
				${INSTALL_DATA} "$$file" ${DESTDIR}${PREFIX}/lib/x11/choosefont/src; \
			    done

	cd ${WRKSRC}/src/output && for file in X.tcl HTML.tcl CSS.tcl name.tcl; do \
			${INSTALL_DATA} "$$file" ${DESTDIR}${PREFIX}/lib/x11/choosefont/src/output; \
			done

	${INSTALL_DATA} ${WRKSRC}/locale/nl_NL.tcl ${DESTDIR}${PREFIX}/lib/x11/choosefont/locale
	${INSTALL_DATA} ${WRKSRC}/locale/en_US.tcl ${DESTDIR}${PREFIX}/lib/x11/choosefont/locale

	ln -s -f ${PREFIX}/lib/x11/choosefont/choosefont.tcl ${DESTDIR}${PREFIX}/bin/choosefont


.include "../../mk/bsd.pkg.mk"
