# $NetBSD: Makefile,v 1.3 2003/08/08 16:12:56 adrian_p Exp $

PKGNAME=		${DISTNAME:S/-/4-client-/}
SVR4_PKGNAME=		mysqc
COMMENT=		MySQL, a free SQL database (client)

CONFLICTS=		{mysql-client-[0-9]*,mysql3-client-[0-9]*}

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-server
CONFIGURE_ARGS+=        --with-openssl
USE_BUILDLINK2=		YES

USE_NEW_TEXINFO=	YES
INFO_FILES=		mysql.info

post-install:
	cd ${PREFIX}/man/man1; ${RM} -f mysqld.1 safe_mysqld.1
	cd ${PREFIX}/share/mysql; ${RM} -f mysql.server
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info

.include "../../devel/readline/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
