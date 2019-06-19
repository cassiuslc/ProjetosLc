-- phpMyAdmin SQL Dump
-- version 4.3.8
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Tempo de geração: 08/11/2016 às 03:37
-- Versão do servidor: 5.6.32-78.1
-- Versão do PHP: 5.4.31

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Banco de dados: `seiap290_Oficial`
--

-- --------------------------------------------------------

--
-- Estrutura para tabela `acidente`
--

CREATE TABLE IF NOT EXISTS `acidente` (
  `acicod` int(11) NOT NULL,
  `acigravidade` varchar(50) NOT NULL,
  `acistatus` varchar(50) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=51 DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estrutura para tabela `ambulancia`
--

CREATE TABLE IF NOT EXISTS `ambulancia` (
  `ambcod` int(11) NOT NULL,
  `ambplaca` varchar(40) COLLATE utf8_unicode_ci NOT NULL,
  `ambtel` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `ambbaicod` int(11) NOT NULL,
  `ambusucod` int(11) NOT NULL
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Fazendo dump de dados para tabela `ambulancia`
--

INSERT INTO `ambulancia` (`ambcod`, `ambplaca`, `ambtel`, `ambbaicod`, `ambusucod`) VALUES
(1, 'JXE-456', '9999-9999', 1, 1),
(2, 'SDR-234', '9999-9999', 1, 2),
(3, 'SDK-323', '9999-9999', 1, 3),
(4, 'JDK-132', '9999-9999', 1, 4);

-- --------------------------------------------------------

--
-- Estrutura para tabela `ausente`
--

CREATE TABLE IF NOT EXISTS `ausente` (
  `auscod` int(11) NOT NULL,
  `ausmotivo` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `aushora` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `ausfuncod` int(11) NOT NULL
) ENGINE=MyISAM AUTO_INCREMENT=11 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Fazendo dump de dados para tabela `ausente`
--

INSERT INTO `ausente` (`auscod`, `ausmotivo`, `aushora`, `ausfuncod`) VALUES
(7, '', '', 2),
(8, 'Nao sei', '', 2),
(9, 'Nao posso atender, motivos medicos', '08/11/2016 - 12:14:00', 2),
(10, 'Ambulancia Bateu', '08/11/2016 - 01:17:50', 48);

-- --------------------------------------------------------

--
-- Estrutura para tabela `bairro`
--

CREATE TABLE IF NOT EXISTS `bairro` (
  `baicod` int(11) NOT NULL,
  `bainome` varchar(100) COLLATE utf8_unicode_ci NOT NULL
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Fazendo dump de dados para tabela `bairro`
--

INSERT INTO `bairro` (`baicod`, `bainome`) VALUES
(1, 'Cidade-Nova'),
(2, 'Coroado'),
(3, 'Nova-cidade');

-- --------------------------------------------------------

--
-- Estrutura para tabela `cargo`
--

CREATE TABLE IF NOT EXISTS `cargo` (
  `carcod` int(11) NOT NULL,
  `carcargo` varchar(50) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;

--
-- Fazendo dump de dados para tabela `cargo`
--

INSERT INTO `cargo` (`carcod`, `carcargo`) VALUES
(2, 'Funcionario'),
(3, 'Admin');

-- --------------------------------------------------------

--
-- Estrutura para tabela `funcionarios`
--

CREATE TABLE IF NOT EXISTS `funcionarios` (
  `funcod` int(11) NOT NULL,
  `funnome` varchar(50) NOT NULL,
  `funcpf` varchar(50) NOT NULL,
  `funsenha` varchar(45) NOT NULL DEFAULT ''
) ENGINE=InnoDB AUTO_INCREMENT=50 DEFAULT CHARSET=latin1;

--
-- Fazendo dump de dados para tabela `funcionarios`
--

INSERT INTO `funcionarios` (`funcod`, `funnome`, `funcpf`, `funsenha`) VALUES
(1, 'juca', '12455556', '123'),
(2, 'ROOT', '056996782', '123'),
(48, 'Davi Lucas', '862.068.202-46', '123'),
(49, 'Eduarda Maria', '780.783.942-25', '123');

-- --------------------------------------------------------

--
-- Estrutura para tabela `locall`
--

CREATE TABLE IF NOT EXISTS `locall` (
  `loccod` int(11) NOT NULL,
  `locx` double NOT NULL,
  `locy` double NOT NULL,
  `locbaicod` int(11) NOT NULL
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Fazendo dump de dados para tabela `locall`
--

INSERT INTO `locall` (`loccod`, `locx`, `locy`, `locbaicod`) VALUES
(1, -3.031539, -59.9956, 1);

-- --------------------------------------------------------

--
-- Estrutura para tabela `motorista`
--

CREATE TABLE IF NOT EXISTS `motorista` (
  `motcod` int(11) NOT NULL,
  `motnome` varchar(50) NOT NULL,
  `motcpf` varchar(50) NOT NULL,
  `motdatan` date NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;

--
-- Fazendo dump de dados para tabela `motorista`
--

INSERT INTO `motorista` (`motcod`, `motnome`, `motcpf`, `motdatan`) VALUES
(1, 'Roberto Brasil', '22296095054', '1996-11-03'),
(3, 'Aldry Saraiva', '72370991836', '2016-11-03');

-- --------------------------------------------------------

--
-- Estrutura para tabela `ocorrencia`
--

CREATE TABLE IF NOT EXISTS `ocorrencia` (
  `ococod` int(11) NOT NULL,
  `ocostatus` varchar(40) COLLATE utf8_unicode_ci NOT NULL,
  `ocos1` int(11) NOT NULL,
  `ocos2` int(11) NOT NULL,
  `ocodata` varchar(12) COLLATE utf8_unicode_ci NOT NULL,
  `ocohora` varchar(12) COLLATE utf8_unicode_ci NOT NULL,
  `ocoseicod` int(11) NOT NULL,
  `ocoacicod` int(11) NOT NULL,
  `ocoloccod` int(11) NOT NULL,
  `ocoambcod` int(11) DEFAULT NULL,
  `ocoobs` varchar(200) COLLATE utf8_unicode_ci DEFAULT NULL
) ENGINE=MyISAM AUTO_INCREMENT=12 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- --------------------------------------------------------

--
-- Estrutura para tabela `seia`
--

CREATE TABLE IF NOT EXISTS `seia` (
  `seicod` int(11) NOT NULL,
  `seiid` int(11) NOT NULL,
  `seistatus` varchar(50) NOT NULL,
  `seimotcod` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;

--
-- Fazendo dump de dados para tabela `seia`
--

INSERT INTO `seia` (`seicod`, `seiid`, `seistatus`, `seimotcod`) VALUES
(2, 1001, 'Offline', 1),
(3, 1152, 'Online', 3);

-- --------------------------------------------------------

--
-- Estrutura para tabela `usuarios`
--

CREATE TABLE IF NOT EXISTS `usuarios` (
  `usucod` int(11) NOT NULL,
  `usulogin` varchar(50) NOT NULL,
  `ususenha` varchar(50) NOT NULL,
  `usucarcod` int(11) NOT NULL,
  `usufuncod` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;

--
-- Fazendo dump de dados para tabela `usuarios`
--

INSERT INTO `usuarios` (`usucod`, `usulogin`, `ususenha`, `usucarcod`, `usufuncod`) VALUES
(1, 'sdnksnfksdnfksnfsdknsdkfnsdkf', 'sdkfnsdkfnsdfksdnfksdn', 2, 1),
(2, 'root', 'seiaroot', 2, 2),
(3, 'maria', 'seiam', 2, 49),
(4, 'davi', 'seiad', 2, 48);

--
-- Índices de tabelas apagadas
--

--
-- Índices de tabela `acidente`
--
ALTER TABLE `acidente`
  ADD PRIMARY KEY (`acicod`);

--
-- Índices de tabela `ambulancia`
--
ALTER TABLE `ambulancia`
  ADD PRIMARY KEY (`ambcod`), ADD KEY `ambbaicod` (`ambbaicod`), ADD KEY `ambusucod` (`ambusucod`);

--
-- Índices de tabela `ausente`
--
ALTER TABLE `ausente`
  ADD PRIMARY KEY (`auscod`), ADD KEY `ausfuncod` (`ausfuncod`);

--
-- Índices de tabela `bairro`
--
ALTER TABLE `bairro`
  ADD PRIMARY KEY (`baicod`);

--
-- Índices de tabela `cargo`
--
ALTER TABLE `cargo`
  ADD PRIMARY KEY (`carcod`);

--
-- Índices de tabela `funcionarios`
--
ALTER TABLE `funcionarios`
  ADD PRIMARY KEY (`funcod`);

--
-- Índices de tabela `locall`
--
ALTER TABLE `locall`
  ADD PRIMARY KEY (`loccod`), ADD KEY `locbaicod` (`locbaicod`);

--
-- Índices de tabela `motorista`
--
ALTER TABLE `motorista`
  ADD PRIMARY KEY (`motcod`);

--
-- Índices de tabela `ocorrencia`
--
ALTER TABLE `ocorrencia`
  ADD PRIMARY KEY (`ococod`), ADD KEY `ocoseicod` (`ocoseicod`), ADD KEY `ocoacicod` (`ocoacicod`), ADD KEY `ocoloccod` (`ocoloccod`), ADD KEY `ocoambcod` (`ocoambcod`);

--
-- Índices de tabela `seia`
--
ALTER TABLE `seia`
  ADD PRIMARY KEY (`seicod`), ADD KEY `seimotcod` (`seimotcod`);

--
-- Índices de tabela `usuarios`
--
ALTER TABLE `usuarios`
  ADD PRIMARY KEY (`usucod`), ADD KEY `usufuncod` (`usufuncod`), ADD KEY `usucarcod` (`usucarcod`);

--
-- AUTO_INCREMENT de tabelas apagadas
--

--
-- AUTO_INCREMENT de tabela `acidente`
--
ALTER TABLE `acidente`
  MODIFY `acicod` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=51;
--
-- AUTO_INCREMENT de tabela `ambulancia`
--
ALTER TABLE `ambulancia`
  MODIFY `ambcod` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT de tabela `ausente`
--
ALTER TABLE `ausente`
  MODIFY `auscod` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=11;
--
-- AUTO_INCREMENT de tabela `bairro`
--
ALTER TABLE `bairro`
  MODIFY `baicod` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT de tabela `cargo`
--
ALTER TABLE `cargo`
  MODIFY `carcod` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT de tabela `funcionarios`
--
ALTER TABLE `funcionarios`
  MODIFY `funcod` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=50;
--
-- AUTO_INCREMENT de tabela `locall`
--
ALTER TABLE `locall`
  MODIFY `loccod` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT de tabela `motorista`
--
ALTER TABLE `motorista`
  MODIFY `motcod` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT de tabela `ocorrencia`
--
ALTER TABLE `ocorrencia`
  MODIFY `ococod` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=12;
--
-- AUTO_INCREMENT de tabela `seia`
--
ALTER TABLE `seia`
  MODIFY `seicod` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT de tabela `usuarios`
--
ALTER TABLE `usuarios`
  MODIFY `usucod` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- Restrições para dumps de tabelas
--

--
-- Restrições para tabelas `seia`
--
ALTER TABLE `seia`
ADD CONSTRAINT `seia_ibfk_1` FOREIGN KEY (`seimotcod`) REFERENCES `motorista` (`motcod`);

--
-- Restrições para tabelas `usuarios`
--
ALTER TABLE `usuarios`
ADD CONSTRAINT `usuarios_ibfk_1` FOREIGN KEY (`usufuncod`) REFERENCES `funcionarios` (`funcod`),
ADD CONSTRAINT `usuarios_ibfk_2` FOREIGN KEY (`usucarcod`) REFERENCES `cargo` (`carcod`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
