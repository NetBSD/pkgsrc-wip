# $NetBSD: Makefile,v 1.4 2014/05/21 14:06:31 ttys Exp $

PKGNAME=	todotxt-2.10
CATEGORIES=	misc
MASTER_SITES=	https://github.com/ginatrapani/todo.txt-cli

COMMENT=	Simple and extensible shell script for managing your todo.txt file
LICENSE=	gnu-gpl-v3

GIT_REPOSITORIES=	todo.txt-cli
GIT_REPO.todo.txt-cli=	git://github.com/ginatrapani/todo.txt-cli.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://todotxt.com/

PKG_DESTDIR_SUPPORT=	user-destdir
DEPENDS=		bash>=4.3:../../shells/bash
DEPENDS+=		bash-completion>=2.1:../../shells/bash-completion

WRKSRC=		${WRKDIR}/todo.txt-cli

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	todo.sh
SUBST_SED.prefix+=	-e "s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},"

USE_TOOLS+=	bash
REPLACE_BASH=	todo.sh

USE_LANGUAGES=	# none

NO_BUILD=	yes

EGDIR=		share/examples/todotxt
DOCDIR=		share/doc/todotxt

INSTALLATION_DIRS=	bin ${DOCDIR} ${EGDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/todo.sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/todo.cfg ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/todo_completion ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README.textile ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
