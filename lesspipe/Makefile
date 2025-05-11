# $NetBSD$

DISTNAME=	lesspipe-2.18
CATEGORIES=	misc
MASTER_SITES=	https://www-zeuthen.desy.de/~friebel/unix/less/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www-zeuthen.desy.de/~friebel/unix/less/
COMMENT=	Displaying more with less
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	bash:run perl:run

REPLACE_BASH+=	lesscomplete lesspipe.sh
REPLACE_PERL+=	archive_color code2color sxw2txt vimcolor

USE_LANGUAGES=	# none

do-configure:
	# nothing

do-build:
	# nothing

do-install:
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/bash-completion
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lesspipe.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/lesspipe.1
	${INSTALL_DATA} ${WRKSRC}/less_completion ${DESTDIR}${PREFIX}/share/bash-completion/less_completion
	${INSTALL_DATA} ${WRKSRC}/_less ${DESTDIR}${PREFIX}/share/zsh/site-functions
.for f in archive_color code2color lesscomplete lesspipe.sh sxw2txt vimcolor
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
