# $NetBSD: Makefile,v 1.1 2013/09/24 11:06:11 fhajny Exp $

DISTNAME=	sphinxtrain-1.0.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cmusphinx/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://cmusphinx.sourceforge.net/
COMMENT=	Acoustic model training tools
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run pkg-config

CONFIGURE_ARGS+=	--with-sphinxbase=auto

REPLACE_PYTHON+=	python/cmusphinx/*.py			\
			python/setup.py				\
			scripts/0000.g2p_train/calculateER.py	\
			scripts/0000.g2p_train/evaluate.py	\
			scripts/sphinxtrain

.include "../../lang/python/application.mk"
.include "../../wip/sphinxbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
