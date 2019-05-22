# $NetBSD: Makefile,v 1.52 2018/12/09 18:52:24 adam Exp $

DISTNAME=	opengrok-1.1
PKGNAME=	opengrok-1.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/oracle/opengrok/releases/download/1.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://oracle.github.io/opengrok/
COMMENT=	Fast and usable source code search and cross reference engine
LICENSE=	cddl-1.0

EXTRACT_USING=	bsdtar

DEPENDS+=	ctags-[0-9]*:../../wip/ctags-git

MESSAGE_SUBST+=		PKG_JAVA_HOME=${PKG_JAVA_HOME}

.include "options.mk"

USE_JAVA=	yes
USE_JAVA2=	yes
NO_BUILD=	yes

CONF_FILES=	${PREFIX}/share/examples/opengrok/paths.tsv \
		${PREFIX}/share/opengrok/var/opengrok/paths.tsv

INSTALLATION_DIRS+=	share/opengrok/bin \
			share/opengrok/lib/lib \
			share/examples/opengrok \
			share/opengrok/var/opengrok

do-install:
	${INSTALL_DATA} ${WRKSRC}/doc/README.md \
		${DESTDIR}${PREFIX}/share/opengrok
	${INSTALL_DATA} ${WRKSRC}/lib/source.war \
		${DESTDIR}${PREFIX}/share/opengrok/lib
	${INSTALL_DATA} ${WRKSRC}/lib/lib/*.jar \
		${DESTDIR}${PREFIX}/share/opengrok/lib/lib
	${INSTALL_DATA} ${WRKSRC}/doc/paths.tsv \
		${DESTDIR}${PREFIX}/share/examples/opengrok

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
