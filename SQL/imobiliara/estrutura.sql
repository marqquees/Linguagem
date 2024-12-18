CREATE SCHEMA `imobiliaria`;

CREATE TABLE `imobiliaria`.`conjugue` (
  `NIF` INT NOT NULL,
  `Nome` VARCHAR(255) NOT NULL,
  `Telefone` VARCHAR(255) NULL,
  `Email` VARCHAR(255) NULL,
  PRIMARY KEY (`NIF`));

CREATE TABLE `imobiliaria`.`proprietario` (
  `NIF` INT NOT NULL,
  `NIFConjugue` INT NULL,
  `Nome` VARCHAR(255) NOT NULL,
  `Telefone` VARCHAR(255) NULL,
  `Email` VARCHAR(255) NULL,
  PRIMARY KEY (`NIF`),
  INDEX `FKProprietario1_idx` (`NIFConjugue` ASC) VISIBLE,
  CONSTRAINT `FKProprietario1`
    FOREIGN KEY (`NIFConjugue`)
    REFERENCES `imobiliaria`.`conjugue` (`NIF`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);

CREATE TABLE `imobiliaria`.`imovel` (
  `ID` INT NOT NULL,
  `NIFProprietario` INT NOT NULL,
  `IDLocalizacao` INT NOT NULL,
  PRIMARY KEY (`ID`),
  INDEX `FKImovel1_idx` (`NIFProprietario` ASC) VISIBLE,
  CONSTRAINT `FKImovel1`
    FOREIGN KEY (`NIFProprietario`)
    REFERENCES `imobiliaria`.`proprietario` (`NIF`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);

ALTER TABLE `imobiliaria`.`imovel` 
ADD INDEX `FKImovel2_idx` (`IDLocalizacao` ASC) VISIBLE;
;
ALTER TABLE `imobiliaria`.`imovel` 
ADD CONSTRAINT `FKImovel2`
  FOREIGN KEY (`IDLocalizacao`)
  REFERENCES `imobiliaria`.`localizacao` (`IDLocalizacao`)
  ON DELETE NO ACTION
  ON UPDATE NO ACTION;


CREATE TABLE `imobiliaria`.`angaria` (
  `NIFConsultor` INT NOT NULL,
  `IDImovel` INT NOT NULL,
  `DataEntrada` DATE NOT NULL,
  PRIMARY KEY (`NIFConsultor`),
  INDEX `FKAngaria2_idx` (`IDImovel` ASC) VISIBLE,
  CONSTRAINT `FKAngaria2`
    FOREIGN KEY (`IDImovel`)
    REFERENCES `imobiliaria`.`imovel` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);

ALTER TABLE `imobiliaria`.`angaria` 
ADD CONSTRAINT `FKAngaria1`
  FOREIGN KEY (`NIFConsultor`)
  REFERENCES `imobiliaria`.`consultor` (`NIF`)
  ON DELETE NO ACTION
  ON UPDATE NO ACTION;

CREATE TABLE `imobiliaria`.`consultor` (
  `NIF` INT NOT NULL,
  `IDAgencia` INT NOT NULL,
  `Nome` VARCHAR(255) NOT NULL,
  `Telefone` VARCHAR(255) NOT NULL,
  `Email` VARCHAR(255) NOT NULL,
  `LandingPage` VARCHAR(255) NULL,
  PRIMARY KEY (`NIF`));

ALTER TABLE `imobiliaria`.`consultor` 
ADD INDEX `FKConsultor1_idx` (`IDAgencia` ASC) VISIBLE;
;
ALTER TABLE `imobiliario`.`consultor` 
ADD CONSTRAINT `FKConsultor1`
  FOREIGN KEY (`IDAgencia`)
  REFERENCES `imobiliaria`.`agencia` (`IDAgencia`)
  ON DELETE NO ACTION
  ON UPDATE NO ACTION;


CREATE TABLE `imobiliaria`.`localizacao` (
  `IDLocalizacao` INT NOT NULL,
  `Rua` VARCHAR(100) NOT NULL,
  `Numero` INT NOT NULL,
  `Habitacao` VARCHAR(10) NOT NULL,
  `CEP` INT NOT NULL,
  `Freguesia` VARCHAR(40) NOT NULL,
  `Concelho` VARCHAR(40) NOT NULL,
  `Distrito` VARCHAR(40) NOT NULL,
  PRIMARY KEY (`IDLocalizacao`));

CREATE TABLE `imobiliaria`.`agencia` (
  `IDAgencia` INT NOT NULL,
  `IDRede` INT NOT NULL,
  `IDLocalizacao` INT NOT NULL,
  `Nome` VARCHAR(255) NOT NULL,
  `LicencaAMI` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`IDAgencia`),
  INDEX `FKAgencia2_idx` (`IDLocalizacao` ASC) VISIBLE,
  CONSTRAINT `FKAgencia2`
    FOREIGN KEY (`IDLocalizacao`)
    REFERENCES `imobiliaria`.`localizacao` (`IDLocalizacao`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);

CREATE TABLE `imobiliaria`.`rede_agencia` (
  `IDRede` INT NOT NULL,
  `DenSocial` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`IDRede`));

ALTER TABLE `imobiliaria`.`agencia` 
ADD INDEX `FKAgencia1_idx` (`IDRede` ASC) VISIBLE;
;
ALTER TABLE `imobiliaria`.`agencia` 
ADD CONSTRAINT `FKAgencia1`
  FOREIGN KEY (`IDRede`)
  REFERENCES `imobiliaria`.`rede_agencia` (`IDRede`)
  ON DELETE NO ACTION
  ON UPDATE NO ACTION;