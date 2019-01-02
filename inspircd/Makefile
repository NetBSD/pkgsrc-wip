# $NetBSD$

DISTNAME=	inspircd-2.0.27
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=inspircd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.inspircd.org/
COMMENT=	Modular Internet Relay Chat (IRC) server
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
USE_TOOLS+=	perl
USE_LANGUAGES=	c c++
HAS_CONFIGURE=	yes
MAKE_FILE=	BSDmakefile

CONFIGURE_ARGS+=	--with-cc="${CXX} ${CXXFLAGS} ${LDFLAGS}"
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--module-dir=${PREFIX}/lib/inspircd/modules
CONFIGURE_ARGS+=	--config-dir=${PREFIX}/etc/inspircd
CONFIGURE_ARGS+=	--data-dir=${PREFIX}/inspircd/data
CONFIGURE_ARGS+=	--log-dir=${PREFIX}/inspircd/logs
CONFIG_SHELL=		${PERL5}

INSTALLATION_DIRS+=	share/examples

.include "options.mk"

post-configure:
.for extra in ${INSPIRCD_EXTRAS}
	cd ${WRKSRC} && ${CONFIGURE_ENV} ${PERL5} ./configure --enable-extras=${extra}
.endfor

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/.gdbargs
	${MV} ${DESTDIR}${PREFIX}/etc/inspircd/examples \
	    ${DESTDIR}${PREFIX}/share/examples/inspircd

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
