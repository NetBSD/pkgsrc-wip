# $NetBSD: Makefile,v 1.1.1.1 2010/03/29 12:12:36 ryo-on Exp $
#

DISTNAME=	ciwiki-1.2.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ciwiki/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://sourceforge.net/projects/ciwiki/
COMMENT=	CiWiki is a small and simple WikiWikiWeb implementation written in C

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	bin \
			${DOCSDIR} \
			${PKGMANDIR}/man1

DOCFILES=	AUTHORS \
		COPYING \
		ChangeLog \
		HOWLOGIN \
		INSTALL \
		NEWS \
		README \
		TODO \
		didiwiki-16.png \
		didiwiki.html \
		didiwiki.png \
		styles.css

MANFILES1=	didiwiki.1

CONFFILES=	didiwiki.conf

GNU_CONFIGURE=	yes

post-install:
.for filename in ${DOCFILES} ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DESTDIR}${DOCSDIR}
.endfor
	${INSTALL_MAN} ${WRKSRC}/${MANFILES1} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
