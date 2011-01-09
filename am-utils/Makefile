# $NetBSD: Makefile,v 1.9 2011/01/09 11:38:41 cheusov Exp $
#

DISTNAME=	am-utils-6.1.5
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.am-utils.org/pub/am-utils/ \
                ftp://ftp.cs.umn.edu/pub/am-utils \
                ftp://ftp.cise.ufl.edu/pub/mirrors/am-utils \
                ftp://ftp.fu-berlin.de/unix/network/am-utils \
                ftp://ftp.tu-darmstadt.de/pub/networking/filesystems/am-utils/ \
                ftp://ftp.sunet.se/pub/unix/admin/am-utils \
                ftp://sunsite.org.uk/package/am-utils \
                ftp://ftp.u-aizu.ac.jp/pub/net/amd/am-utils \
                ftp://core.ring.gr.jp/pub/net/am-utils/ \
                ftp://ftp.ring.gr.jp/pub/net/am-utils/

MAINTAINER=		cheusov@tut.by
HOMEPAGE=		http://www.am-utils.org/
COMMENT=		Berkeley automounter suite of utilities
LICENSE=		original-bsd

USE_TOOLS+=		yacc lex perl:run
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

INFO_FILES=		yes

CONFIGURE_ARGS+=	--without-ldap
CONFIGURE_ARGS+=	--without-hesiod
CONFIGURE_ARGS+=	--without-ndbm

RCD_SCRIPTS=		amd-pkgsrc

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
PKGDOCDIR=		${PREFIX}/share/doc/${PKGBASE}

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	${EGDIR} ${PKGDOCDIR} etc/amd

EXTRA_DOC_FILES=	COPYING FAQ ChangeLog BUGS AUTHORS \
                        README.attrcache README.autofs README.ldap \
                        README.osx README.y2k NEWS README INSTALL
EXAMPLE_CONF_FILES=	amd.conf lostaltmail.conf

post-install:
.for i in ${EXTRA_DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PKGDOCDIR}
.endfor
.for i in ${EXAMPLE_CONF_FILES}
	${INSTALL_DATA} ${WRKSRC}/scripts/${i}-sample ${DESTDIR}${EGDIR}/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
