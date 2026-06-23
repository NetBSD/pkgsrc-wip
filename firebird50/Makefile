# $NetBSD$
#
DISTNAME=		Firebird-5.0.4.1812-0-source
PKGNAME=		firebird-5.0.4
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_GITHUB:=FirebirdSQL/}
GITHUB_PROJECT=		firebird
GITHUB_RELEASE=		v5.0.4
EXTRACT_SUFX=		.tar.xz
LICENSE=		mpl-1.1

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		https://www.firebirdsql.org/
COMMENT=		SQL database, opensource version of InterBase

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		cmake gmake

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-client-only \
			--with-gnu-ld \
			--with-fbmsg=${PREFIX}/share/firebird \
			--sysconfdir=${PKG_SYSCONFDIR} \
			--libexecdir=${PREFIX}/libexec

.if ${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "i386"
CXXFLAGS+=		-msse4.2
.endif

INSTALLATION_DIRS=	lib share/firebird

do-install:
	cp -R ${WRKSRC}/gen/Release/firebird/include \
		${DESTDIR}${PREFIX}
	${INSTALL_DATA} ${WRKSRC}/gen/Release/firebird/firebird.msg \
		${DESTDIR}${PREFIX}/share/firebird/
	${INSTALL_LIB} ${WRKSRC}/gen/Release/firebird/lib/libfbclient.so.5.0.4 \
		${DESTDIR}${PREFIX}/lib
	${LN} -s ${DESTDIR}${PREFIX}/lib/libfbclient.so.5.0.4 \
		${DESTDIR}${PREFIX}/lib/libfbclient.so.2
	${LN} -s ${DESTDIR}${PREFIX}/lib/libfbclient.so.5.0.4 \
		${DESTDIR}${PREFIX}/lib/libfbclient.so

.include "../../devel/readline/buildlink3.mk"
.include "../../security/libtomcrypt/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
