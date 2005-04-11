# $NetBSD: Makefile,v 1.2 2005/04/11 21:13:14 tvierling Exp $

DISTNAME=	msn-transport-1.2.8rc1
PKGNAME=	jabberd-msn-1.2.8
CATEGORIES=	chat
MASTER_SITES=	http://msn-transport.jabberstudio.org/

MAINTAINER=	david@netbsd-fr.org
COMMENT=	Jabber MSN-Transport module

USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --with-jabberd=${PREFIX}/include/jabberd \
		 --with-pth=${PREFIX}/include \

CONFIGURE_ENV=  LDFLAGS=-L${LOCALBASE}/lib
EXAMPLEFILE=	${PREFIX}/share/examples/jabberd/jabberd-msn.xml
MESSAGE_SUBST+=	EXAMPLEFILE=${EXAMPLEFILE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/msntrans.so ${PREFIX}/lib/jabberd/
	${INSTALL_DATA} ${WRKSRC}/msnt.xml ${EXAMPLEFILE}

.include "../../chat/jabberd/buildlink3.mk"
.include "../../devel/pth/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
