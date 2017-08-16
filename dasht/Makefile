# $NetBSD$

DISTNAME=	dasht-2.2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=sunaku/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sunaku/dasht/
COMMENT=	Search API docs offline, in terminal or browser
LICENSE=	isc

USE_TOOLS+=	wget:run

DEPENDS+=	socat-[0-9]*:../../net/socat
DEPENDS+=	sqlite3-[0-9]*:../../databases/sqlite3
DEPENDS+=	w3m-[0-9]*:../../www/w3m

USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

DASHT_MANPAGES= \
	dasht-docsets-extract.1 \
	dasht-docsets-install.1 \
	dasht-docsets-remove.1 \
	dasht-docsets-update.1 \
	dasht-docsets.1 \
	dasht-query-exec.1 \
	dasht-query-html.1 \
	dasht-query-line.1 \
	dasht-server-http.1 \
	dasht-server.1 \
	dasht.1 

DASHT_SCRIPTS= \
	dasht \
	dasht-docsets \
	dasht-docsets-extract \
	dasht-docsets-install \
	dasht-docsets-remove \
	dasht-docsets-update \
	dasht-query-exec \
	dasht-query-html \
	dasht-query-line \
	dasht-server \
	dasht-server-http 

do-install:
.for _m_ in ${DASHT_MANPAGES}
	${INSTALL_MAN} ${WRKSRC}/man/man1/${_m_} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor
.for _s_ in ${DASHT_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${_s_} ${DESTDIR}${PREFIX}/bin
.endfor

.include "../../mk/bsd.pkg.mk"
